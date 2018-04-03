package main

import (
	"fmt"
	"math/rand"
)

func test_all(water *[width][height]float64, surface *[width][height]float64) {
	for x := range water {
		for y := range water[x] {
			if water[x][y] < 0 {
				exit("en effet")
			}
			water[x][y] += 0.000777075436904

		}
	}
	test_water(water)
	for x := range water {
		for y := range water[x] {
			if water[x][y] < 0 {
				exit("en effet")
			}
			water[x][y] += surface[x][y] + 0.000777075436904

		}
	}
	test_suface(surface)
	test_water(water)
}

func test_water(water *[width][height]float64) {
	fmt.Println("")
	fmt.Println("testwater")
	fmt.Println("")
	for x := range water {
		fmt.Println(water[x])
	}
	fmt.Println("")
	fmt.Println("")
}

func test_suface(surface *[width][height]float64) {
	print("\n")
	print("\n")
	for x := range surface {
		fmt.Println(surface[x])
		print("\n")

	}
	print("\n")
	print("\n")
}

func water_gen(mode int, water *[width][height]float64, surface *[width][height]float64, hauteurfloat int, time int) {
	hauteur := int(hauteurfloat)
	if hauteur > 3720 {
		test_water(water)
		exit("ended")
	}
	if mode == 1 {
		if hauteur < time && hauteur%5 == 0 {
			for x := range water[1] {
				water[1][x] += 2
				water[int(height-2)][x] += 2
				water[x][1] += 2
				water[x][int(width-2)] += 2
			}
		}
		mode_pluie1(water, surface)
		mode_pluie2(water, surface)
		mode_pluie3(water, surface)
		mode_pluie4(water, surface)
		// 	mode_pluie1(water, surface)
		// 	mode_pluie2(water, surface)
		// 	mode_pluie3(water, surface)
		// 	mode_pluie4(water, surface)
		// 	mode_pluie1(water, surface)
		// 	mode_pluie2(water, surface)
		// 	mode_pluie3(water, surface)
		// 	mode_pluie4(water, surface)
	}
	if mode == 2 {
		if hauteur < time && hauteur%5 == 0 {
			for x := range water[1] {
				water[1][x] += 10
			}
		}
		// if hauteur > 300 {
		// 	test_all(water, surface)
		// 	exit("finished")
		// }
		mode_pluie1(water, surface)
		mode_pluie2(water, surface)
		mode_pluie3(water, surface)
		mode_pluie4(water, surface)
	}
	if mode == 3 {
		if hauteur < time {
			for g := 0; g < 20; g++ {
				x := rand.Intn(int(width))
				y := rand.Intn(int(height))
				water[x][y] += 1
			}
		}
		if hauteur%4 == 0 {
			mode_pluie1(water, surface)
		}
		if hauteur%4 == 1 {
			mode_pluie2(water, surface)
		}
		if hauteur%4 == 2 {
			mode_pluie3(water, surface)
		}
		if hauteur%4 == 3 {
			mode_pluie4(water, surface)
		}
	}
}

func find_min(tab [4]float64) int {
	var i int = 0
	var min float64 = tab[0]
	for j := 1; j < 4; j++ {
		if tab[j] < min {
			min = tab[j]
			i = j
		}
	}
	// fmt.Println(tab, i)
	return i
}

func mode_pluie1(water *[width][height]float64, surface *[width][height]float64) {
	var i int
	var j int
	var tab [4]float64
	i = 1
	for i < int(width-1) {
		j = 1
		for j < int(height-1) {
			if water[i][j] > 0.05 {
				taille := float64(water[i][j]) + float64(surface[i][j])
				tab[0] = float64(water[i+1][j]) + float64(surface[i+1][j])
				tab[1] = float64(water[i][j+1]) + float64(surface[i][j+1])
				tab[2] = float64(water[i][j-1]) + float64(surface[i][j-1])
				tab[3] = float64(water[i-1][j]) + float64(surface[i-1][j])
				min := find_min(tab)
				diff := taille - tab[min]
				// if diff > 2*water[i][j] {
				// 	diff = 2 * water[i][j]
				// }
				// if diff > water[i][j] {
				// 	diff = water[i][j]
				// 	exit("yolo")
				// }
				if diff > 0 {
					if min == 0 {
						water[i][j] -= diff / 2
						water[i+1][j] += diff / 2
					} else if min == 1 {
						water[i][j] -= diff / 2
						water[i][j+1] += diff / 2
					} else if min == 2 {
						water[i][j] -= diff / 2
						water[i][j-1] += diff / 2
					} else if min == 3 {
						water[i][j] -= diff / 2
						water[i-1][j] += diff / 2
					}
				}

			}
			j += 2
		}
		i += 2
	}

}

func mode_pluie2(water *[width][height]float64, surface *[width][height]float64) {
	var i int
	var j int
	var tab [4]float64
	i = 2
	for i < int(width-1) {
		j = 1
		for j < int(height-1) {
			if water[i][j] > 0.05 {
				taille := float64(water[i][j]) + float64(surface[i][j])
				tab[0] = float64(water[i+1][j]) + float64(surface[i+1][j])
				tab[1] = float64(water[i][j+1]) + float64(surface[i][j+1])
				tab[2] = float64(water[i][j-1]) + float64(surface[i][j-1])

				tab[3] = float64(water[i-1][j]) + float64(surface[i-1][j])
				min := find_min(tab)
				diff := taille - tab[min]
				// if diff > 2*water[i][j] {
				// 	diff = 2 * water[i][j]
				// }
				if diff > 0 {
					if min == 0 {
						water[i][j] -= diff / 2
						water[i+1][j] += diff / 2
					} else if min == 1 {
						water[i][j] -= diff / 2
						water[i][j+1] += diff / 2
					} else if min == 2 {
						water[i][j] -= diff / 2
						water[i][j-1] += diff / 2
					} else if min == 3 {
						water[i][j] -= diff / 2
						water[i-1][j] += diff / 2
					}
				}

			}
			j += 2
		}
		i += 2
	}

}
func mode_pluie3(water *[width][height]float64, surface *[width][height]float64) {
	var i int
	var j int
	var tab [4]float64
	i = 1
	for i < int(width-1) {
		j = 2
		for j < int(height-1) {
			if water[i][j] > 0.05 {
				taille := float64(water[i][j]) + float64(surface[i][j])
				tab[0] = float64(water[i+1][j]) + float64(surface[i+1][j])
				tab[1] = float64(water[i][j+1]) + float64(surface[i][j+1])
				tab[2] = float64(water[i][j-1]) + float64(surface[i][j-1])

				tab[3] = float64(water[i-1][j]) + float64(surface[i-1][j])
				min := find_min(tab)
				diff := taille - tab[min]
				// if diff > 2*water[i][j] {
				// 	diff = 2 * water[i][j]
				// }
				if diff > 0 {
					if min == 0 {
						water[i][j] -= diff / 2
						water[i+1][j] += diff / 2
					} else if min == 1 {
						water[i][j] -= diff / 2
						water[i][j+1] += diff / 2
					} else if min == 2 {
						water[i][j] -= diff / 2
						water[i][j-1] += diff / 2
					} else if min == 3 {
						water[i][j] -= diff / 2
						water[i-1][j] += diff / 2
					}
				}

			}
			j += 2
		}
		i += 2
	}

}
func mode_pluie4(water *[width][height]float64, surface *[width][height]float64) {
	var i int
	var j int
	var tab [4]float64
	i = 2
	for i < int(width-1) {
		j = 2
		for j < int(height-1) {
			if water[i][j] > 0.05 {
				taille := float64(water[i][j]) + float64(surface[i][j])
				tab[0] = float64(water[i+1][j]) + float64(surface[i+1][j])
				tab[1] = float64(water[i][j+1]) + float64(surface[i][j+1])
				tab[2] = float64(water[i][j-1]) + float64(surface[i][j-1])

				tab[3] = float64(water[i-1][j]) + float64(surface[i-1][j])
				min := find_min(tab)
				diff := taille - tab[min]
				// if diff > 2*water[i][j] {
				// 	diff = 2 * water[i][j]
				// }
				if diff > 0 {
					if min == 0 {
						water[i][j] -= diff / 2
						water[i+1][j] += diff / 2
					} else if min == 1 {
						water[i][j] -= diff / 2
						water[i][j+1] += diff / 2
					} else if min == 2 {
						water[i][j] -= diff / 2
						water[i][j-1] += diff / 2
					} else if min == 3 {
						water[i][j] -= diff / 2
						water[i-1][j] += diff / 2
					}
				}

			}
			j += 2
		}
		i += 2
	}

}
