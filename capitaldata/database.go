package main

import (
	"database/sql"
	"fmt"
	"strings"
)

//fonction se connectant qu serveur sql
// créé une database si celle si n'existe pas
//cree une table si ell n'exsite pas
func init_database(db_user string, db_passw string) *sql.DB {
	db, err := sql.Open("mysql", db_user+":"+db_passw+"@tcp(127.0.0.1:3306)/")
	_, err = db.Exec("CREATE DATABASE if not exists testtechst")
	handle_err(err)
	_, err = db.Exec("USE testtechst")
	handle_err(err)
	fmt.Println("Connected to database")
	rows, err := db.Query("CREATE TABLE if not exists csv_file(first_name CHAR(50), last_name CHAR(50), email CHAR(100), date DATETIME);")
	handle_err(err)
	fmt.Println("table created")
	defer rows.Close()
	return db
}

//Fonction verifiant que 2 que l'email n'est pas déjà dans la base
func email_exist(db *sql.DB, email string) int {
	request_string := "SELECT * FROM csv_file WHERE email = " + "'" + email + "';"
	request, err := db.Query(request_string)
	handle_err(err)
	defer request.Close()
	for request.Next() {
		return 1
	}
	return 0

}

func complete_database(db *sql.DB, file [][]string) {
	for i := range file {
		request := "INSERT INTO csv_file VALUES("
		//on verifie que le csv possedait 4 elements par tableau
		if len(file[i]) == 4 {
			//on cree la requete sql
			for j := range file[i] {
				if j < 3 {
					request += "'" + file[i][j] + "'" + ","
				} else {
					//Ce code permet de transformer le RDC3339 en format date compréhensible par mysql
					file[i][j] = strings.Replace(file[i][j], "T", " ", 1)
					file[i][j] = strings.Replace(file[i][j], "Z", "", 1)
					request += "'" + file[i][j] + "'" + ")"
				}
			}
			//on execute la requete sql si le mail n'est pas deja dans la base
			if email_exist(db, file[i][2]) == 1 {
				fmt.Println("L'émail ", file[i][2], "existe déjà")
			} else {
				fmt.Println(request)
				_, err := db.Exec(request)
				handle_err(err)
			}
		}
	}
}
