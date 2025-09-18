fn resolve(max: u32) -> u32 {
    let mut x: u32 = 1;
    let mut y: u32 = 2;
    let mut sum: u32 = y;

    while y < max {
       
        let x1: u32 = y;
        let y2: u32 = x + y;

        if y2 % 2 == 0 {
            sum += y2;
        }

        x = x1;
        y = y2;
    }

    return sum;
}

fn main() {
    let result: u32 = resolve(4000000);
    println!("Result={}", result);
}
