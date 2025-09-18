package main

import "fmt"

func main() {

	var example_result int = example()

	fmt.Printf("Example=%d\n", example_result)

	var problem_result int = problem()

	fmt.Printf("Result=%d\n", problem_result)

}

func resolve(factor int) int {

	var sum_square int
	var sum int

	for i := 1; i <= factor; i++ {
		sum_square += i * i
		sum += i
	}

	square_sum := sum * sum

	result := square_sum - sum_square

	return result
}

func example() int {
	return resolve(10)
}

func problem() int {
	return resolve(100)
}
