package main

import "fmt"

func main() {

	var example_result int = example()

	fmt.Printf("Example=%d\n", example_result)

	var problem_result int = problem()

	fmt.Printf("Result=%d\n", problem_result)

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

func example() int {
	return resolve(13195)
}

func problem() int {
	return resolve(600851475143)
}
