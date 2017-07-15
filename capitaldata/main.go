package main

import (
	"database/sql"
	"encoding/csv"
	"flag"
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

func charge_in_dtb(db *sql.DB, name_file string, db_user string, db_passw string) {
	data, err := read_file(name_file)
	if err != 1 {
		//recuperation du csv dans un tableau
		r := csv.NewReader(strings.NewReader(data))
		records, err := r.ReadAll()
		handle_err(err)
		//completer la base de donnés
		complete_database(db, records)
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
	//intiliser la base de donnee
	db := init_database(*db_user, *db_passw)
	fi, err := os.Stat(*name_file)
	handle_err(err)
	//S'il le lien est un dossier, on iterate sur tous les fichiers du repertoire
	if fi.IsDir() {
		files, err := ioutil.ReadDir(*name_file)
		handle_err(err)
		for _, f := range files {
			charge_in_dtb(db, f.Name(), *db_user, *db_passw)
		}
	} else { // Sinon on charge juste le fichier
		charge_in_dtb(db, *name_file, *db_user, *db_passw)
	}
	db.Close()
}
