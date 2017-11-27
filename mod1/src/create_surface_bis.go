package main

import (
	"math"
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

func find_dist_most_proche(l_point []point) []int {
	var proche []int
	for i := range l_point {
		yolo := []point{point{0, 0, l_point[i].x}, point{0, 0, l_point[i].y}, point{0, 0, width - l_point[i].x}, point{0, 0, height - l_point[i].y}}
		tri_à_bulle(yolo)
		max_dist := yolo[3].z / 2
		if max_dist * 2 > l_point[i].z {
			max_dist = l_point[i].z
		}
		// TODO: find le point le plus proche
		if max_dist < 11 {
			max_dist = 20
		}
		proche = append(proche, int(max_dist))
	}
	return proche
}

func distance(a point, b point) float64 {

	abx := a.x - b.x
	aby := a.y - b.y
	return math.Sqrt(abx*abx + aby*aby)
}

func put_point(pt point, distance_max int, surface *[width][height]float64) {
	var dist float64 = float64(distance_max)
	startx := int(pt.x - dist + 1)
	starty := int(pt.y - dist + 1)
	var t_point point
	for i := startx; i <= int(pt.x+dist - 1); i++ {
		for j := starty; j <= int(pt.y+dist - 1); j++ {
			t_point = point{float64(i), float64(j), 0.1}
			distance_actuelle := (float64(distance(pt, t_point)) / (dist))
			if distance_actuelle <= 1 {
				surface[i][j] = float64(int(pt.z * (1 - (distance_actuelle) * (distance_actuelle)) + distance_actuelle * distance_actuelle * surface[i][j]))
			}

		}
	}
}

func generate_surface(surface *[width][height]float64, l_point []point) {
	var x int
	var y int
	//var z int
	dist := find_dist_most_proche(l_point)
	for i := range l_point {
		x = int(l_point[i].x)
		y = int(l_point[i].y)
		//z = int(l_point[i].z)
		if l_point[i].z >= surface[x][y] {
			put_point(l_point[i], dist[i], surface)
		} else {
			put_point(l_point[i], dist[i], surface)
		}
	}
	// test_suface(surface)
}

func create_surface_bis(surface *[width][height]float64, test [][]string) {
	list_point := string_to_point(test)
	tri_à_bulle(list_point)
	generate_surface(surface, list_point)

}
