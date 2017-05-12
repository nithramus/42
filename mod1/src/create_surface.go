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

func projection_x(surface *[width][height]float32, list_point []point) {
	var j float32
	var last_point point = point{0, 0, 0}
	var b bezier
	var value float32

	for i := range list_point {
		for j := range list_point {
			value = dist(list_point[i], list_point[int(j)])
			if value > surface[int(list_point[int(j)].x)][int(list_point[i].y)] || i != j {
				surface[int(list_point[int(j)].x)][int(list_point[i].y)] = value
			}
		}
	}
	for i := range list_point {
		last_point = point{list_point[i].x, 0, 0}
		for j = 0; float32(j) < height; j++ {
			if surface[int(list_point[i].x)][int(j)] != 0 {

				fmt.Println("##################### result\n", surface[int(list_point[i].x)][int(j)]*float32(7/8), "test")
				b = bezier{
					last_point,
					point{list_point[i].x, j, surface[int(list_point[i].x)][int(j)]},
					point{0, 0, surface[int(list_point[i].x)][int(j)] * float32(float32(2)/float32(8))},
					point{0, 0, surface[int(list_point[i].x)][int(j)] * float32(float32(8)/float32(8))}}
				bezier_func(b, surface)
				last_point = point{list_point[i].x, j, surface[int(list_point[i].x)][int(j)]}
			}
		}
		b = bezier{last_point, point{list_point[i].x, j - 1, 0}, point{0, 0, last_point.z * float32(float32(7)/float32(8))}, point{0, 0, last_point.z * float32(float32(1)/float32(4))}}
		bezier_func(b, surface)

	}
}

func projection_y(surface *[width][height]float32) {
	var last_point point = point{0, 0, 0}
	var b bezier
	var i int

	for j := 0; float32(j) < height-1; j++ {
		last_point = point{0, float32(j), 0}
		for i = 0; float32(i) < width-1; i++ {
			if surface[int(i)][int(j)] != 0 {
				fmt.Println("test")
				b = bezier{last_point, point{float32(i), float32(j), surface[int(i)][int(j)]}, last_point, point{0, 0, 0}}
				bezier_func_y(b, surface)
				last_point = point{float32(i), float32(j), surface[int(i)][int(j)]}
			}
		}
		b = bezier{last_point, point{float32(i), float32(j), 0}, point{0, 0, 0}, point{0, 0, 0}}
		bezier_func_y(b, surface)

	}
}

func create_surface(surface *[width][height]float32) {

	var list_point []point

	list_point = append(list_point, point{40, 40, 100})
	list_point = append(list_point, point{80, 80, 100})
	//	list_point = append(list_point, point{70, 35, 150})
	//	list_point = append(list_point, point{80, 45, 200})
	projection_x(surface, list_point)
	for i := 0; float32(i) < width; i++ {
		fmt.Println(surface[int(i)])
	}
	//	projection_y(surface)
	fmt.Println((surface[40]))

	//b := bezier{point{0, 0, 200}, point{25, 25, 200}, point{5, 5, 10}, point{10, 10, 255}}
	//bezier_func(b, surface)
}
