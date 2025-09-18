function main() {

    var result = resolve(3, 5, 1000)

    console.log("Result=%d\n", result)

}

function resolve(n1, n2, max) {

    var sum = 0;

    for (let i = 1; i < max; i++) {

        if (i % n1 == 0) {
            sum += i
        } else if (i % n2 == 0) {
            sum += i
        }
    }

    return sum
}

main()