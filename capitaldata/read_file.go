package main

import (
	"fmt"
	"io/ioutil"
	"regexp"
)

//Fonction lisant le fichier passé en paremètre, et retourne son
//contenu dans une string
func read_file(name string) (string, int) {
	//verifier l'extension de fichier
	regex := regexp.MustCompile("(.+\\.csv)$")
	if regex.MatchString(name) == false {
		fmt.Println("Erreur", name, ": Extension de fichier incorrect")
		return "", 1
	}
	data, err := ioutil.ReadFile(name)
	handle_err(err)
	return string(data), 0
}
