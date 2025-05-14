package main

import "fmt"

func main() {

	var example_result int = example()

	fmt.Printf("Example=%d\n", example_result)

	var problem_result int = problem()

	fmt.Printf("Result=%d\n", problem_result)

}

func resolve(factor int) int {

	var smallest_multiple int
	num := factor
	for smallest_multiple == 0 {

		var remainder_sum int
		for i := 2; i <= factor; i++ {

			remainder_sum += num % i

		}

		if remainder_sum == 0 {
			smallest_multiple = num
		}

		num++
	}

	return smallest_multiple
}

func example() int {
	return resolve(10)
}

func problem() int {
	return resolve(20)
}
