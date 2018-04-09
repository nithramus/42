package main

func bezier_func_y(list bezier, tab *[width][height]float64) {
	var t float64 = 0
	var x float64

	for list.start.x+x <= list.end.x {
		t = float64(x) / float64((list.end.x - list.start.x))
		tab[int(list.start.x+x)][int(list.start.y)] = float64(bez_deg3(list.start, list.end, list.po1, list.po2, t))
		x++
	}
}
