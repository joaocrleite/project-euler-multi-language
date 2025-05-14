package main

import "fmt"

func main() {

	var example_result int = example()

	fmt.Printf("Example=%d\n", example_result)

	var problem_result int = problem()

	fmt.Printf("Result=%d\n", problem_result)

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

func example() int {
	return resolve(3, 5, 10)
}

func problem() int {
	return resolve(3, 5, 1000)
}
