package main

import "fmt"

func main() {

	var example_result int = example()

	fmt.Printf("Example=%d\n", example_result)

	var problem_result int = problem()

	fmt.Printf("Result=%d\n", problem_result)

}

func resolve(factor int) int {

	var a, b, c int
	var done bool

	for i := 2; i < factor; i++ {

		for y := i + 1; y < factor; y++ {

			for z := y + 1; z < factor; z++ {

				a = i
				b = y
				c = z

				if a+b+c == factor {
					aa := a * a
					bb := b * b
					cc := c * c

					if aa+bb == cc {
						done = true
						break
					}

				}

			}

			if done {
				break
			}

		}
		if done {
			break
		}
	}

	result := a * b * c

	return result
}

func example() int {
	return resolve(12)
}

func problem() int {
	return resolve(1000)
}
