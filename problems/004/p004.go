package main

import "fmt"

func main() {

	var example_result int = example()

	fmt.Printf("Example=%d\n", example_result)

	var problem_result int = problem()

	fmt.Printf("Result=%d\n", problem_result)

}

func resolve(digits int) int {

	var largest_palindrome int

	top := 1
	for i := 0; i < digits; i++ {
		top *= 10
	}
	min := top / 10
	top -= 1

	for x := top; x > min; x-- {
		for y := top; y > min; y-- {

			product := x * y

			if product > largest_palindrome {
				product_str := fmt.Sprintf("%d", product)
				reversed_product_str := ""
				for _, v := range product_str {
					reversed_product_str = string(v) + reversed_product_str
				}

				if product_str == reversed_product_str {
					largest_palindrome = product
				}
			}

		}
	}

	return largest_palindrome
}

func example() int {
	return resolve(2)
}

func problem() int {
	return resolve(3)
}
