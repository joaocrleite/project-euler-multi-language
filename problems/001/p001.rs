fn resolve(n1: u32, n2: u32, max: u32) -> u32 {
    let mut sum: u32 = 0;
    let mut i: u32 = n1;

    loop {
        if i >= max {
            break;
        }

        if i % n1 == 0 || i % n2 == 0 {
            sum += i;
        }

        i += 1;
    }

    return sum;
}

fn main() {
    let result = resolve(3, 5, 1000);
    println!("Result={}", result);
}
