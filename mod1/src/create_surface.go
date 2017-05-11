package main

import (
	"fmt"
)

func dist(point1 point, point2 point) float32 {
	var value float32 = float32(point1.x - point2.x)
	if value < 0 {
		value = -value
	}
	return_value := float32(point1.z) - (value * 7)
	if return_value < 0 {
		return 0
	}
	return return_value
}

func projection_x(surface *[width][height]float32, list_point [2]point) {
	var j float32
	var last_point point = point{0, 0, 0}
	var b bezier

	for i := 0; i < 2; i++ {
		for j = 0; j < 2; j++ {
			surface[int(list_point[int(j)].x)][int(list_point[i].y)] = dist(list_point[i], list_point[int(j)])
		}
	}
	for i := 0; i < 2; i++ {
		last_point = point{list_point[i].x, 0, 0}
		for j = 0; float32(j) < height; j++ {
			if surface[int(list_point[i].x)][int(j)] != 0 {
				fmt.Println("test")
				b = bezier{last_point, point{list_point[i].x, j, surface[int(list_point[i].x)][int(j)]}, point{40, 10, 25}, last_point}
				bezier_func(b, surface)
				last_point = point{list_point[i].x, j, surface[int(list_point[i].x)][int(j)]}
			}
		}
		b = bezier{last_point, point{list_point[i].x, j - 1, 0}, last_point, point{40, 10, 25}}
		bezier_func(b, surface)

	}
}

func projection_y(surface *[width][height]float32, list_point [2]point) {
	var last_point point = point{0, 0, 0}
	var b bezier
	var i int

	for j := 0; float32(j) < height-1; j++ {
		last_point = point{float32(j), 0, 0}
		for i = 0; float32(i) < width-1; i++ {
			if surface[int(i)][int(j)] != 0 {
				fmt.Println("test")
				b = bezier{last_point, point{float32(i), float32(j), surface[int(i)][int(j)]}, point{40, 10, 25}, last_point}
				bezier_func(b, surface)
				last_point = point{float32(i), float32(j), surface[int(i)][int(j)]}
			}
		}
		b = bezier{last_point, point{float32(i), float32(j), 0}, last_point, point{40, 10, 25}}
		bezier_func(b, surface)

	}
}

func create_surface(surface *[width][height]float32) {
	//	var i float32
	//	var j float32

	var list_point [2]point

	list_point[0], list_point[1] = point{40, 10, 100}, point{10, 40, 100}
	projection_x(surface, list_point)
	//	projection_y(surface, list_point)

	//b := bezier{point{0, 0, 200}, point{25, 25, 200}, point{5, 5, 10}, point{10, 10, 255}}
	//bezier_func(b, surface)
}
