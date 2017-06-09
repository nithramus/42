package main

import (
	"encoding/csv"
	"fmt"
	"io/ioutil"
	"log"
	//"regexp"
	"strings"
	//"os"
	"database/sql"
	_ "github.com/go-sql-driver/mysql"
	"reflect"
)

func read_file(name string) string {
	data, err := ioutil.ReadFile(name)
	if err != nil {
		log.Fatal(err)
	}
	return string(data)
}

func init_database() *sql.DB {
	db, err := sql.Open("mysql", "root:1234@tcp(127.0.0.1:3306)/test")
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("Connected to database")
	rows, err := db.Query("CREATE TABLE if not exists csv_file(first_name CHAR(50), last_name CHAR(50), email CHAR(100), date DATETIME);")
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("table created")
	defer rows.Close()
	return db
}

func complete_database(db *sql.DB, file [][]string) {
	for i := range file {
		request := "INSERT INTO csv_file VALUES("
		for j := range file[i] {
			if j < 3 {
				request += "'" + file[i][j] + "'" + ","
			} else {
				file[i][j] = strings.Replace(file[i][j], "T", " ", 1)
				file[i][j] = strings.Replace(file[i][j], "Z", "", 1)
				request += "'" + file[i][j] + "'" + ")"
			}
		}
		fmt.Println(request)
		rows, err := db.Query(request)
		if err != nil {
			log.Fatal(err)
		}
		defer rows.Close()
	}
}

func main() {
	data := read_file("testtech.csv")
	fmt.Println(data)
	r := csv.NewReader(strings.NewReader(data))
	records, err := r.ReadAll()
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(reflect.TypeOf(records))
	db := init_database()
	fmt.Println(records)
	complete_database(db, records)
	db.Close()
	/*	for i := range records {
		for j := range records[i] {
			fmt.Println(records[i][j])
		}
	}*/
}
