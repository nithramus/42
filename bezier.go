package main

import "fmt"

//import "runtime/debug"

type point struct {
	x int
	y int
	z int
}

type bezier struct {
	start point
	end   point
	po1   point
	po2   point
}

func power(value float64, power float64) float64 {
	var i float64 = 0
	var ret float64 = 1
	for i < power {
		ret = ret * value
		i++
	}
	return ret
}

func bez_deg3(p0 point, p1 point, p2 point, p3 point, t float64) float64 {

	var ret float64 = float64(p0.z) * power(1-t, 3)
	ret = ret + 3*float64(p2.z)*t*power(1-t, 2)
	ret = ret + 3*float64(p3.z)*t*power(1-t, 2)
	ret = ret + float64(p1.z)*power(t, 3)
	return ret
}

func bezier_func(list bezier, tab *[20000][20000]int) {
	var t float64 = 0
	y := 0

	for list.start.y+y <= list.end.y {
		t = float64(y) / float64((list.end.y - list.start.y))
		tab[list.start.x][list.start.y+y] = int(bez_deg3(list.start, list.end, list.po1, list.po2, t))
		fmt.Println(t)
		fmt.Println(tab[list.start.x][list.start.y+y])
		y++
	}
}

func main() {
	var tab [20000][20000]int
	b := bezier{point{50, 50, 10}, point{50, 150, 1500}, point{50, 75, 10}, point{50, 125, 15000}}
	bezier_func(b, &tab)
	//fmt.Println(tab[12])
	fmt.Println("yolo")
}
