<?php

function resolve($max): int
{
    $x = 1;
    $y = 2;
    $sum = $y;

    while ($y < $max) {
        $x1 = $y;
        $y2 = $x + $y;

        if ($y2 % 2 == 0) {
            $sum += $y2;
        }

        $x = $x1;
        $y = $y2;
    }

    return $sum;
}

function main()
{
    $result = resolve(4000000);

    echo "Result=$result\n";
}

main();
