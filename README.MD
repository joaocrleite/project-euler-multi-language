# Project Euler problems in different programming languages

https://projecteuler.net/

### Progress Languages

- C
- C++
- Zig
- Rust
- Go
- NodeJS
- Python
- Java
- PHP

## Versions
java 21.0.8

node 20.19.4

python 3.12.3

zig 0.13.0

go 1.22.2

g++ 13.3.0 std c++17

gcc 13.3.0 std c11

php 8.3.6

rust 1.89.0


### Run

```

chmod +x run_problem.sh

./run_problem.sh 001                 # run all languages in problems/001
./run_problem.sh 001 cpp             # run only p001.cpp
./run_problem.sh 001 "cpp,py,go"     # run only these languages
./run_problem.sh 7 py js             # accepts unpadded ID; runs Python & JS

```


## Example
`./run_problem.sh 3 c,go`

```
========================================================
Problem 003
Path: problems/003
Filters: c go
Running: go c
========================================================
────────────────────────────────────────────────────────
▶ Go → problems/003/p003.go
────────────────────────────────────────────────────────
Result=6857
⏱  Duration: 65 ms
✅ Exit code: 0

────────────────────────────────────────────────────────
▶ C (gcc) → problems/003/p003.c
────────────────────────────────────────────────────────
Result=6857
⏱  Duration: 1 ms
✅ Exit code: 0
```