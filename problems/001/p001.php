<?php

function main()
{
    $result = resolve(3, 5, 1000);

    echo "Result=$result\n";;
}

function resolve(int $n1, int $n2, int $max): int
{

    $sum = 0;

    for ($i = 1; $i < $max; $i++) {
        if ($i % $n1 == 0) {
            $sum += $i;
        } else if ($i % $n2 == 0) {
            $sum += $i;
        }
    }

    return $sum;
}

main();
