package main

//import "runtime/debug"

type point struct {
	x float32
	y float32
	z float32
}

type bezier struct {
	start point
	end   point
	po1   point
	po2   point
}

func power(value float32, power float32) float32 {
	var i float32 = 0
	var ret float32 = 1
	for i < power {
		ret = ret * value
		i++
	}
	return ret
}

func bez_deg3(p0 point, p1 point, p2 point, p3 point, t float32) float32 {

	var ret float32 = float32(p0.z) * power(1-t, 3)
	ret = ret + 3*float32(p2.z)*t*power(1-t, 2)
	ret = ret + 3*float32(p3.z)*(1-t)*power(t, 2)
	ret = ret + float32(p1.z)*power(t, 3)
	return ret
}

func bezier_func(list bezier, tab *[width][height]float32) {
	var t float32 = 0
	var y float32

	for list.start.y+y <= list.end.y {
		t = float32(y) / float32((list.end.y - list.start.y))
		tab[int(list.start.x)][int(list.start.y+y)] = float32(bez_deg3(list.start, list.end, list.po1, list.po2, t))
		y++
	}
}

/*	b := bezier{point{50, 50, 10}, point{50, 150, 1500}, point{50, 75, 10}, point{50, 125, 15000}}
	bezier_func(b, &tab)
*/
