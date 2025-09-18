package main

import "fmt"

func main() {

	var example_result int = example()

	fmt.Printf("Example=%d\n", example_result)

	var problem_result int = problem()

	fmt.Printf("Result=%d\n", problem_result)

}

func isPrime(num int) bool {

	if num < 4 {
		return true
	}

	for i := 2; i < num; i++ {

		if num%i == 0 {
			return false
		}

	}

	return true
}

func resolve(factor int) int {

	var last_prime int
	var prime_count int
	num := 2

	for prime_count < factor {

		is_prime := isPrime(num)

		if is_prime {
			last_prime = num
			prime_count++
		}

		num++

	}

	return last_prime
}

func example() int {
	return resolve(6)
}

func problem() int {
	return resolve(10001)
}
