package main

import "fmt"

func main() {

	var result int = resolve(600851475143)

	fmt.Printf("Result=%d\n", result)

}

func resolve(num int) int {

	var largest_prime int

	for num != 1 {
		for prime := 2; prime <= num; prime++ {
			if num%prime == 0 {
				if largest_prime < prime {
					largest_prime = prime
				}

				num /= prime
				break
			}
		}
	}

	return largest_prime
}
