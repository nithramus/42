package main

import (
	"fmt"
	"math/rand"
)

func water_gen(mode int, water *[width][height]block, surface *[width][height]float64, hauteur float64) {
	if mode == 1 {
		mode_normal(water, surface, hauteur)
	}
	if mode == 2 {
		if int(hauteur)%20 == 0 {
			for x := range water {
				water[0][x].block += 1
			}
		}

		mode_vague(water, surface)
	}
	if mode == 3 {
		x := rand.Intn(int(width))
		y := rand.Intn(int(height))
		water[x][y].block += 1
		fmt.Println(x)
		mode_vague(water, surface)
	}
}

func mode_pluie(water *[width][height]block, surface *[width][height]float64) {

}

func mode_normal(water *[width][height]block, surface *[width][height]float64, hauteur float64) {
	i := 0
	for i < int(width) {
		for j := range water {
			if surface[i][j] < hauteur {
				water[i][j].height += 1
				water[i][j].todraw = 1
			}
		}
		i++
	}
}

func mode_vague(water *[width][height]block, surface *[width][height]float64) {
	var i int
	var j int
	for i < int(width) {
		j = 0
		for j < int(height) {
			if int16(water[i][j].block) > water[i][j].height {
				if water[i][j].height == 0 {
					water[i][j].height += 1
					water[i][j].todraw = 1
				} else {
					taille := float64(water[i][j].block) + float64(surface[i][j]) - 1
					if i < int(height-1) && float64(water[i+1][j].block)+float64(surface[i+1][j]) < taille {
						water[i][j].block -= 1
						water[i+1][j].block += 1
					} else if j < int(height-1) && float64(water[i][j+1].block)+float64(surface[i][j+1]) < taille {
						water[i][j].block -= 1
						water[i][j+1].block += 1

					} else if j >= 1 && float64(water[i][j-1].block)+float64(surface[i][j-1]) < taille {
						water[i][j].block -= 1
						water[i][j-1].block += 1

					} else if i >= 1 && float64(water[i-1][j].block)+float64(surface[i-1][j]) < taille {
						water[i][j].block -= 1
						water[i-1][j].block += 1
					}

					if water[i][j].height != int16(water[i][j].block) {
						water[i][j].height = int16(water[i][j].block)
						water[i][j].todraw = 1
					}
				}
			}
			j++
		}

		i++
	}
}
