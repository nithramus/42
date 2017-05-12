package main

func bezier_func_y(list bezier, tab *[width][height]float32) {
	var t float32 = 0
	var x float32

	for list.start.x+x <= list.end.x {
		t = float32(x) / float32((list.end.x - list.start.x))
		tab[int(list.start.x+x)][int(list.start.y)] = float32(bez_deg3(list.start, list.end, list.po1, list.po2, t))
		x++
	}
}

/*	b := bezier{point{50, 50, 10}, point{50, 150, 1500}, point{50, 75, 10}, point{50, 125, 15000}}
	bezier_func(b, &tab)
*/
