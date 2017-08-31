package main

import (
	"fmt"
	"strconv"
)

func tri_à_bulle(list_point []point) {
	var ok int = 1
	var tmp point
	for ok == 1 {
		ok = 0
		for i := range list_point {
			if i != 0 {
				if list_point[i-1].z < list_point[i].z {
					tmp = list_point[i-1]
					list_point[i-1] = list_point[i]
					list_point[i] = tmp
					ok = 1
				}
			}
		}
	}
}

func string_to_point(list [][]string) []point {
	var list_point []point
	for i := range list {

		cor1, _ := strconv.ParseFloat(list[i][1], 64)
		cor2, _ := strconv.ParseFloat(list[i][2], 64)
		cor3, _ := strconv.ParseFloat(list[i][3], 64)
		if cor1 == 0 || cor2 == 0 || cor1 > width-1 || cor2 > height-1 {
			exit("Coordonnée ayant pour valeur 0")
		}
		list_point = append(list_point, point{cor1, cor2, cor3})
	}
	return list_point

}

func find_dist_most_proche(l_point []point) []point {
	var proche []point
	for i := range l_point {
		for j := range l_point {
		}
	}
}

func find_distance(first point, second point) {

}

func put_point(pt point, dist int, surface *[width][height]float64) {

}

func generate_surface(surface *[width][height]float64, l_point []point) {
	var x int
	var y int
	var z int
	for i := range l_point {
		x = int(l_point[i].x)
		y = int(l_point[i].y)
		z = int(l_point[i].z)
		if l_point[i].z >= surface[x][y] {
			put_point(l_point[i], z, surface)
		} else {
			z = find_dist_most_proche()

			put_point(l_point[i], z, surface)
		}
	}
}

func create_surface_bis(surface *[width][height]float64, test [][]string) {
	list_point := string_to_point(test)
	tri_à_bulle(list_point)
	fmt.Println(list_point)
	exit("Fin du prog")
}
