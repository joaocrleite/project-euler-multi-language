package main

import "fmt"

func main() {

	var example_result int = example()

	fmt.Printf("Example=%d\n", example_result)

	var problem_result int = problem()

	fmt.Printf("Result=%d\n", problem_result)

}

// Take to long time, need to be improved research better ways to identify if a num if prime
func isPrime(num int) bool {

	if num < 4 {
		return true
	}

	max := num/2 + 1

	for i := 2; i <= max; i++ {

		if num%i == 0 {

			return false
		}
	}

	return true
}

func resolve(below int) int {

	var primes_sum int

	for i := 2; i < below; i++ {

		is_prime := isPrime(i)

		if is_prime {
			primes_sum += i
		}

	}

	return primes_sum
}

func example() int {
	return resolve(10)
}

func problem() int {
	return resolve(2000000)
}
