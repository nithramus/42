package main

import (
	"flag"
	"fmt"
	"strings"
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

	option := flag.String("option", "value", "message erreur")
	flag.Parse()
	fmt.Println("yolo", *option)
	create_surface(&surface)
	if strings.Compare(*option, "draw") == 0 {
		draw(&surface, &water)
	}

}
