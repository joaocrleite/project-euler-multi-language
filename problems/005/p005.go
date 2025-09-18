package main

import "fmt"

func main() {

	var result int =  resolve(20)

	fmt.Printf("Result=%d\n", result)

}

func resolve(factor int) int {

	var smallest_multiple int
	num := factor
	for smallest_multiple == 0 {

		var match = true
		for i := 2; i <= factor; i++ {

			if num % i != 0 {
				match = false;
				break;
			}

		}

		if match {
			smallest_multiple = num
		}

		num++
	}

	return smallest_multiple
}
