function resolve(max) {
  let x = 1;
  let y = 2;
  let sum = y;

  while (y < max) {
    const x1 = y;
    const y2 = x + y;

    if (y2 % 2 == 0) {
      sum += y2;
    }

    x = x1;
    y = y2;
  }

  return sum;
}

function main() {
  const result = resolve(4000000);

  console.log("Result=%d", result);
}

main();
