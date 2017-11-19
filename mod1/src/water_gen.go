package main

import (
	"fmt"
	"math/rand"
)

func test_water(water *[width][height]block) {
	print("\n")
	print("\n")
	for x := range water {
		for y := range water[x] {
			print(int(water[x][y].block), " ")
		}
		print("\n")

	}
	print("\n")
	print("\n")
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

func water_gen(mode int, water *[width][height]block, surface *[width][height]float64, hauteurfloat int) {
	hauteur := int(hauteurfloat)
	if mode == 2 {
		if hauteur < 100000 && hauteur % 20 == 0 {
			for x := range water[1] {
				water[1][x].block += 2
			}
		}
		// if hauteur > 2000 {
		// 	for x := range water[1] {
		// 		// water[1][x].block = 0
		//
		// 	}
		// }
		mode_pluie1(water, surface)
		mode_pluie2(water, surface)
		mode_pluie3(water, surface)
		mode_pluie4(water, surface)
		mode_pluie1(water, surface)
		mode_pluie2(water, surface)
		mode_pluie3(water, surface)
		mode_pluie4(water, surface)
		mode_pluie1(water, surface)
		mode_pluie2(water, surface)
		mode_pluie3(water, surface)
		mode_pluie4(water, surface)

		//test_water(water)
		//test_suface(surface)
	}
	if mode == 3 {
		if hauteur < 20000 {
			for g := 0; g < 50; g++ {
				x := rand.Intn(int(width))
				y := rand.Intn(int(height))
				water[x][y].block += 1
			}
		}
		mode_pluie1(water, surface)
		mode_pluie2(water, surface)
		mode_pluie3(water, surface)
		mode_pluie4(water, surface)
		// mode_pluie(water, surface)
	}
}
func find_min(tab [4]float64) (int) {
	var i int = 0
	var min float64 = tab[0]
	for j := 1; j < 4; j++ {
		if tab[j] < min {
			min = tab[j]
			i = j
		}
	}
	//print(tab[min])
	return i
}

func mode_pluie1(water *[width][height]block, surface *[width][height]float64) {
	var i int
	var j int
	var tab [4]float64
	// TODO: resetup un 1 sur deux, et un changement de sens ?
	i = 1
	for i < int(width-1) {
		j = 1
		for j < int(height-1) {
			if int16(water[i][j].block) != 0 {
				taille := float64(water[i][j].block) + float64(surface[i][j])
				tab[0] = float64(water[i+1][j].block) + float64(surface[i+1][j])
				tab[1] = float64(water[i][j+1].block) + float64(surface[i][j+1])
				tab[2] = float64(water[i][j-1].block) + float64(surface[i][j-1])

				tab[3] = float64(water[i-1][j].block) + float64(surface[i-1][j])
				min := find_min(tab)
				diff := taille - tab[min]
				if diff > 2 * water[i][j].block {
					diff = 2 * water[i][j].block
				}
				if diff > 0 {
					if min == 0 {
						water[i][j].block -= diff / 2
						water[i+1][j].block += diff / 2
						//	WATER[i+1][j].todraw = 1
					} else if min == 1 {
						water[i][j].block -= diff / 2
						water[i][j+1].block += diff / 2
						//	water[i][j+1].todraw = 1
					} else if min == 2 {
						water[i][j].block -= diff / 2
						water[i][j-1].block += diff / 2
						//water[i][j-1].todraw = 1
					} else if min == 3 {
						water[i][j].block -= diff / 2
						water[i-1][j].block += diff / 2
					}
				}

			}
			j +=2
		}
		i += 2
	}

}

func mode_pluie2(water *[width][height]block, surface *[width][height]float64) {
	var i int
	var j int
	var tab [4]float64
	// TODO: resetup un 1 sur deux, et un changement de sens ?
	i = 2
	for i < int(width-1) {
		j = 1
		for j < int(height-1) {
			if int16(water[i][j].block) != 0 {
				taille := float64(water[i][j].block) + float64(surface[i][j])
				tab[0] = float64(water[i+1][j].block) + float64(surface[i+1][j])
				tab[1] = float64(water[i][j+1].block) + float64(surface[i][j+1])
				tab[2] = float64(water[i][j-1].block) + float64(surface[i][j-1])

				tab[3] = float64(water[i-1][j].block) + float64(surface[i-1][j])
				min := find_min(tab)
				diff := taille - tab[min]
				if diff > 2 * water[i][j].block {
					diff = 2 * water[i][j].block
				}
				if diff > 0 {
					if min == 0 {
						water[i][j].block -= diff / 2
						water[i+1][j].block += diff / 2
						//	WATER[i+1][j].todraw = 1
					} else if min == 1 {
						water[i][j].block -= diff / 2
						water[i][j+1].block += diff / 2
						//	water[i][j+1].todraw = 1
					} else if min == 2 {
						water[i][j].block -= diff / 2
						water[i][j-1].block += diff / 2
						//water[i][j-1].todraw = 1
					} else if min == 3 {
						water[i][j].block -= diff / 2
						water[i-1][j].block += diff / 2
					}
				}

			}
			j +=2
		}
		i += 2
	}

}
func mode_pluie3(water *[width][height]block, surface *[width][height]float64) {
	var i int
	var j int
	var tab [4]float64
	// TODO: resetup un 1 sur deux, et un changement de sens ?
	i = 1
	for i < int(width-1) {
		j = 2
		for j < int(height-1) {
			if int16(water[i][j].block) != 0 {
				taille := float64(water[i][j].block) + float64(surface[i][j])
				tab[0] = float64(water[i+1][j].block) + float64(surface[i+1][j])
				tab[1] = float64(water[i][j+1].block) + float64(surface[i][j+1])
				tab[2] = float64(water[i][j-1].block) + float64(surface[i][j-1])

				tab[3] = float64(water[i-1][j].block) + float64(surface[i-1][j])
				min := find_min(tab)
				diff := taille - tab[min]
				if diff > 2 * water[i][j].block {
					diff = 2 * water[i][j].block
				}
				if diff > 0 {
					if min == 0 {
						water[i][j].block -= diff / 2
						water[i+1][j].block += diff / 2
						//	WATER[i+1][j].todraw = 1
					} else if min == 1 {
						water[i][j].block -= diff / 2
						water[i][j+1].block += diff / 2
						//	water[i][j+1].todraw = 1
					} else if min == 2 {
						water[i][j].block -= diff / 2
						water[i][j-1].block += diff / 2
						//water[i][j-1].todraw = 1
					} else if min == 3 {
						water[i][j].block -= diff / 2
						water[i-1][j].block += diff / 2
					}
				}

			}
			j +=2
		}
		i += 2
	}

}
func mode_pluie4(water *[width][height]block, surface *[width][height]float64) {
	var i int
	var j int
	var tab [4]float64
	// TODO: resetup un 1 sur deux, et un changement de sens ?
	i = 2
	for i < int(width-1) {
		j = 2
		for j < int(height-1) {
			if int16(water[i][j].block) != 0 {
				taille := float64(water[i][j].block) + float64(surface[i][j])
				tab[0] = float64(water[i+1][j].block) + float64(surface[i+1][j])
				tab[1] = float64(water[i][j+1].block) + float64(surface[i][j+1])
				tab[2] = float64(water[i][j-1].block) + float64(surface[i][j-1])

				tab[3] = float64(water[i-1][j].block) + float64(surface[i-1][j])
				min := find_min(tab)
				diff := taille - tab[min]
				if diff > 2 * water[i][j].block {
					diff = 2 * water[i][j].block
				}
				if diff > 0 {
					if min == 0 {
						water[i][j].block -= diff / 2
						water[i+1][j].block += diff / 2
						//	WATER[i+1][j].todraw = 1
					} else if min == 1 {
						water[i][j].block -= diff / 2
						water[i][j+1].block += diff / 2
						//	water[i][j+1].todraw = 1
					} else if min == 2 {
						water[i][j].block -= diff / 2
						water[i][j-1].block += diff / 2
						//water[i][j-1].todraw = 1
					} else if min == 3 {
						water[i][j].block -= diff / 2
						water[i-1][j].block += diff / 2
					}
				}

			}
			j += 2
		}
		i += 2
	}

}
