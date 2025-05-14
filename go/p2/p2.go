package main

import "fmt"

func main() {

	var example_result int = example()

	fmt.Printf("Example=%d\n", example_result)

	var problem_result int = problem()

	fmt.Printf("Result=%d\n", problem_result)

}

func resolve(max int) int {

	n1 := 1
	n2 := 2
	even_sum := 2
	for i := 2; i < max; i++ {

		temp := n1 + n2

		if temp > max {
			break
		}

		if temp%2 == 0 {
			even_sum += temp
		}

		if i%2 == 0 {

			n1 = temp

		} else {
			n2 = temp
		}
	}

	return even_sum
}

func example() int {
	return resolve(100)
}

func problem() int {
	return resolve(4000000)
}
