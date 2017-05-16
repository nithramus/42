package main

import (
	"flag"
	"fmt"
	"strings"
	//	"os"
)

const (
	width  float32 = 100
	height float32 = 100
)

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
	var surface [width][height]float32
	var water [width][height][]float32

	water[0][0] = append(water[0][0], 0)
	option := flag.String("option", "value", "message erreur")
	flag.Parse()
	fmt.Println("yolo", *option)
	create_surface(&surface)
	if strings.Compare(*option, "draw") == 0 {
		draw(&surface, &water)
	}

}
