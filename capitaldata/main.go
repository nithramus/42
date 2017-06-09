package main

import (
	"database/sql"
	"encoding/csv"
	"flag"
	"fmt"
	_ "github.com/go-sql-driver/mysql"
	"io/ioutil"
	"log"
	"os"
	"strings"
)

func handle_err(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

//Fonction lisant le fichier passé en paremètre, et retourne son
//contenu dans une string
func read_file(name string) string {
	data, err := ioutil.ReadFile(name)
	handle_err(err)
	return string(data)
}

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
		if email_exist(db, file[i][2]) == 1 {
			fmt.Println("L'émail ", file[i][2], "existe déjà")
		} else {
			fmt.Println(request)
			_, err := db.Exec(request)
			handle_err(err)
		}

	}
}

func main() {
	//déclaration des différents flags
	name_file := flag.String("file", "testtech.csv", "No input file")
	db_user := flag.String("user", "root", "No database User")
	db_passw := flag.String("passwd", "1234", "No database password")
	flag.Parse()
	if len(os.Args) == 0 {
		flag.Usage()
		os.Exit(1)
	}
	data := read_file(*name_file)
	//recuperation du csv dans un tableau
	r := csv.NewReader(strings.NewReader(data))
	records, err := r.ReadAll()
	handle_err(err)
	//intiliser la base de donnee
	db := init_database(*db_user, *db_passw)
	//completer la base de donnés
	complete_database(db, records)
	db.Close()
}
