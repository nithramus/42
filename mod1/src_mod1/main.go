package main

import "fmt"

const i int = 15

func puissance(value int, power int) int {
	a := 0
	ret := 1

	for a < power {
		ret = ret * value
		a++
	}
	return ret
}

func main() {
	i := 0
	b := [5]int{1, 1, 1, 1, 1}
	for i < 15 {
		a := "test"
		fmt.Println(puissance(i, 10))
		fmt.Println(a)
		fmt.Println(b)
		fmt.Println("vim-go")
		i++
	}
}
