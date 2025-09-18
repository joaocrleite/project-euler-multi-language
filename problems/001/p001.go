package main

import "fmt"

func main() {

	var result int = resolve(3, 5, 1000)

	fmt.Printf("Result=%d\n", result)

}

func resolve(n1 int, n2 int, max int) int {

	var sum int

	for i := 1; i < max; i++ {

		if i%n1 == 0 {
			sum += i
		} else if i%n2 == 0 {
			sum += i
		}
	}

	return sum
}
