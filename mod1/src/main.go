package main

import (
	"flag"
	"fmt"
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
	if *mode < 1 || *mode > 3 {
		fmt.Println("Seulement 3 mode, 1, 2 ou 3")
	} else {
		draw(&surface, &water, *mode)
	}

}
