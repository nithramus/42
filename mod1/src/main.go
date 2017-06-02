package main

import (
	"flag"
	"fmt"
	"io/ioutil"
	"os"
	"regexp"
)

const (
	width  float64 = 100
	height float64 = 100
)

type block struct {
	height int16
	todraw int8
	block  int16
}

func exit(str string) {
	fmt.Println(str)
	os.Exit(0)
}

func puissance(value int, power int) int {
	a := 0
	ret := 1

	for a < power {
		ret = ret * value
		a++
	}
	return ret
}

func main() {
	var surface [width][height]float64
	var water [width][height]block

	mode := flag.Int("mode", 1, "erreur dans le mode")
	flag.Parse()
	file, err := ioutil.ReadFile("test")
	if err != nil {
		panic("")
	}
	yolo := regexp.MustCompile("^(([[:space:]]*\\(([0-9]+,)([0-9]+,)([0-9]+)\\))+[[:space:]]*)$")
	if yolo.MatchString(string(file)) == false {
		fmt.Println("erreur d'input file")
	}
	re := regexp.MustCompile(" *\\((?:([0-9]+),)(?:([0-9]+),)([0-9]+)\\)")
	test := re.FindAllStringSubmatch(string(file), -1)
	create_surface(&surface, test)
	for x := range water {
		water[x][0].block = 20000
		water[x][int(width-1)].block = 20000
	}
	for y := range water[0] {
		water[0][y].block = 20000
		water[int(height-1)][y].block = 20000
	}
	if *mode < 1 || *mode > 3 {
		fmt.Println("Seulement 3 mode, 1, 2 ou 3")
	} else {
		draw(&surface, &water, *mode)
	}

}
