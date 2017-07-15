package main

import (
	//	"fmt"
	"strconv"
)

func dist(point1 point, point2 point) float64 {
	var value float64 = float64(point1.x - point2.x)
	if value < 0 {
		value = -value
	}
	return_value := float64(point1.z) - (value * 7)
	if return_value < 0 {
		return 0
	}
	return return_value
}

func projection_x(surface *[width][height]float64, list_point []point) {
	var j float64
	var last_point point = point{0, 0, 0}
	var b bezier
	var value float64

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
		for j = 0; float64(j) < height; j++ {
			if surface[int(list_point[i].x)][int(j)] != 0 {
				b = bezier{
					last_point,
					point{list_point[i].x, j, surface[int(list_point[i].x)][int(j)]},
					point{0, 0, surface[int(list_point[i].x)][int(j)] * float64(float64(2)/float64(8))},
					point{0, 0, surface[int(list_point[i].x)][int(j)] * float64(float64(8)/float64(8))}}
				bezier_func(b, surface)
				last_point = point{list_point[i].x, j, surface[int(list_point[i].x)][int(j)]}
			}
		}
		b = bezier{last_point, point{list_point[i].x, j - 1, 0}, point{0, 0, last_point.z * float64(float64(7)/float64(8))}, point{0, 0, last_point.z * float64(float64(1)/float64(8))}}
		bezier_func(b, surface)

	}
}

func projection_y(surface *[width][height]float64) {
	var last_point point = point{0, 0, 0}
	var b bezier
	var i int

	for j := 0; float64(j) < height-1; j++ {
		last_point = point{0, float64(j), 0}
		for i = 0; float64(i) < width-1; i++ {
			if surface[int(i)][int(j)] != 0 {
				//fmt.Println("test")
				b = bezier{last_point, point{float64(i), float64(j), surface[int(i)][int(j)]}, last_point, point{0, 0, 0}}
				bezier_func_y(b, surface)
				last_point = point{float64(i), float64(j), surface[int(i)][int(j)]}
			}
		}
		b = bezier{last_point, point{float64(i), float64(j), 0}, point{0, 0, 0}, point{0, 0, 0}}
		bezier_func_y(b, surface)

	}
}

func create_surface(surface *[width][height]float64, test [][]string) {

	var list_point []point

	for i := range test {
		cor1, _ := strconv.ParseFloat(test[i][1], 64)
		cor2, _ := strconv.ParseFloat(test[i][2], 64)
		cor3, _ := strconv.ParseFloat(test[i][3], 64)
		if cor1 == 0 || cor2 == 0 || cor1 > width-1 || cor2 > height-1 {
			exit("Coordonnée ayant pour valeur 0")
		}
		list_point = append(list_point, point{cor1, cor2, cor3})
	}
	//	list_point = append(list_point, point{150, 150, 90})
	//	list_point = append(list_point, point{170, 70, 90})
	projection_x(surface, list_point)
	/*for i := 0; float64(i) < width; i++ {
		fmt.Println(surface[int(i)])
	}*/
	projection_y(surface)
	//fmt.Println((surface[40]))

}
