package main

//import "runtime/debug"

type point struct {
	x float64
	y float64
	z float64
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
	ret = ret + 3*float64(p3.z)*(1-t)*power(t, 2)
	ret = ret + float64(p1.z)*power(t, 3)
	return ret
}

func bezier_func(list bezier, tab *[width][height]float64) {
	var t float64 = 0
	var y float64

	for list.start.y+y <= list.end.y {
		t = float64(y) / float64((list.end.y - list.start.y))
		tab[int(list.start.x)][int(list.start.y+y)] = float64(bez_deg3(list.start, list.end, list.po1, list.po2, t))
		y++
	}
}
