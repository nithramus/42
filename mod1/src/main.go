package main

import (
	"flag"
	"fmt"
	"regexp"
	//	"os"
)

const (
	width  float64 = 50
	height float64 = 50
)

type block struct {
	height int16
	todraw int8
	block  int16
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
	create_surface(&surface)
	yolo := regexp.MustCompile("^(( *\\(([0-9]+,)([0-9]+,)([0-9]+)\\))+)$")
	if yolo.MatchString("(1500,1550,1555)    (1,2,3)") {
		fmt.Println(yolo.MatchString("(1500,1550,1555)"))
	}
	re := regexp.MustCompile(" *\\((?:([0-9]+),)(?:([0-9]+),)([0-9]+)\\)")
	test := re.FindAllStringSubmatch("(1500,1550,1555) (2000,2500,2550) (1200,1250,125)", -1)
	fmt.Println(test, "\nyolo :", test[1][1])
	panic("")
	if *mode < 1 || *mode > 3 {
		fmt.Println("Seulement 3 mode, 1, 2 ou 3")
	} else {
		draw(&surface, &water, *mode)
	}

}
