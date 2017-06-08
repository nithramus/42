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
)

func read_file(name string) string {
	data, err := ioutil.ReadFile(name)
	if err != nil {
		log.Fatal(err)
	}
	return string(data)
}

func init_database() {
	db, err := sql.Open("mysql", "root:1234@tcp(127.0.0.1:3306)/mysql")
	if err != nil {
		log.Fatal(err)
	}
	rows, err := db.Query("use test")
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(rows)

}

func main() {
	data := read_file("testtech.csv")
	fmt.Println(data)
	r := csv.NewReader(strings.NewReader(data))
	records, err := r.ReadAll()
	if err != nil {
		log.Fatal(err)
	}
	init_database()
	fmt.Println(records)
	/*	for i := range records {
		for j := range records[i] {
			fmt.Println(records[i][j])
		}
	}*/
}
