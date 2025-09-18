#!/usr/bin/env bash
set -euo pipefail

# -------- Helpers --------

have() { command -v "$1" >/dev/null 2>&1; }

usage() {
  cat <<'EOF'
Usage:
  ./run_problem.sh <problem_id> [langs...]

Examples:
  ./run_problem.sh 001                 # run all languages in problems/001
  ./run_problem.sh 001 cpp             # run only p001.cpp
  ./run_problem.sh 001 "cpp,py,go"     # run only these languages
  ./run_problem.sh 7 py js             # accepts unpadded ID; runs Python & JS

Valid language filters (aliases):
  js, javascript, node      -> js
  py, python                -> py
  go, golang                -> go
  php                       -> php
  java                      -> java
  rs, rust                  -> rs
  zig                       -> zig
  c                         -> c   (gcc)
  cpp, c++                  -> cpp (g++)

Looks for files like:
  problems/001/p001.js|py|go|php|java|rs|zig|c|cpp
EOF
}

# Normalize language alias to canonical extension
normalize_lang() {
  local raw="${1,,}"  # lowercase
  case "$raw" in
    js|javascript|node) echo "js" ;;
    py|python)          echo "py" ;;
    go|golang)          echo "go" ;;
    php)                echo "php" ;;
    java)               echo "java" ;;
    rs|rust)            echo "rs" ;;
    zig)                echo "zig" ;;
    c)                  echo "c" ;;
    cpp|c++)            echo "cpp" ;;
    *)                  echo "" ;;
  esac
}

# Timer wrapper
run_with_timer() {
  local title="$1"; shift
  local start_ns end_ns dur_ms status
  start_ns=$(date +%s%N 2>/dev/null || true)

  echo "────────────────────────────────────────────────────────"
  echo "▶ $title"
  echo "────────────────────────────────────────────────────────"

  set +e
  "$@"
  status=$?
  set -e

  end_ns=$(date +%s%N 2>/dev/null || true)

  if [[ -n "${start_ns:-}" && -n "${end_ns:-}" ]]; then
    dur_ms=$(( (end_ns - start_ns)/1000000 ))
    echo "⏱  Duration: ${dur_ms} ms"
  else
    echo "⏱  Duration: (timer unavailable)"
  fi

  if [[ $status -ne 0 ]]; then
    echo "❌ Exit code: $status"
  else
    echo "✅ Exit code: 0"
  fi
  echo
}

# -------- Main --------

[[ $# -ge 1 ]] || { usage; exit 1; }

# Problem id (zero-pad if numeric)
raw_id="$1"; shift
if [[ "$raw_id" =~ ^[0-9]+$ ]]; then
  printf -v pid "%03d" "$raw_id"
else
  pid="$raw_id"
fi

prob_dir="problems/$pid"
base="p$pid"

if [[ ! -d "$prob_dir" ]]; then
  echo "⚠️  Folder not found: '$prob_dir'"
  exit 1
fi

# All supported canonical extensions (execution order)
ALL_EXTS=(js py go php java rs zig c cpp)

# Parse optional language filters
declare -a filters=()
if [[ $# -gt 0 ]]; then
  # Allow space and/or comma separated inputs
  IFS=',' read -r -a first_split <<< "$1"
  if [[ ${#first_split[@]} -gt 1 && $# -eq 1 ]]; then
    filters=("${first_split[@]}")
  else
    # collect all args, split any commas inside them
    tmp=()
    for a in "$@"; do
      IFS=',' read -r -a parts <<< "$a"
      tmp+=("${parts[@]}")
    done
    filters=("${tmp[@]}")
  fi
fi

# Build list of exts to run
declare -a exts_to_run=()
if [[ ${#filters[@]} -eq 0 ]]; then
  exts_to_run=("${ALL_EXTS[@]}")
else
  declare -A seen=()
  for f in "${filters[@]}"; do
    norm="$(normalize_lang "$f")"
    if [[ -z "$norm" ]]; then
      echo "⚠️  Ignoring unknown language filter: '$f'"
      continue
    fi
    # keep order as in ALL_EXTS
    seen["$norm"]=1
  done
  for e in "${ALL_EXTS[@]}"; do
    [[ -n "${seen[$e]+x}" ]] && exts_to_run+=("$e")
  done
  if [[ ${#exts_to_run[@]} -eq 0 ]]; then
    echo "⚠️  No valid language filters provided; running all."
    exts_to_run=("${ALL_EXTS[@]}")
  fi
fi

echo
echo "========================================================"
echo "Problem $pid"
echo "Path: $prob_dir"
if [[ ${#filters[@]} -gt 0 ]]; then
  echo "Filters: ${filters[*]}"
fi
echo "Running: ${exts_to_run[*]}"
echo "========================================================"

found_any=false

for ext in "${exts_to_run[@]}"; do
  file="$prob_dir/$base.$ext"
  [[ -f "$file" ]] || continue
  found_any=true

  case "$ext" in
    js)
      if have node; then
        run_with_timer "Node.js → $file" node "$file"
      else
        echo "❗ Skipping JS: node not found"; echo
      fi
      ;;
    py)
      if have python3; then
        run_with_timer "Python → $file" python3 "$file"
      else
        echo "❗ Skipping Python: python3 not found"; echo
      fi
      ;;
    go)
      if have go; then
        run_with_timer "Go → $file" go run "$file"
      else
        echo "❗ Skipping Go: go not found"; echo
      fi
      ;;
    php)
      if have php; then
        run_with_timer "PHP → $file" php "$file"
      else
        echo "❗ Skipping PHP: php not found"; echo
      fi
      ;;
    java)
      if have javac && have java; then
        (
          cd "$prob_dir"
          rm -f "$base.class"
          javac "$base.java"
        )
        run_with_timer "Java → $file" java -cp "$prob_dir" "$base"
        (
          rm -f "$prob_dir/$base.class"
        )
      else
        echo "❗ Skipping Java: javac/java not found"; echo
      fi
      ;;
    rs)
      if have rustc; then
        bin="$prob_dir/$base-rs-bin"
        (
          cd "$prob_dir"
          rustc "$base.rs" -O -o "$base-rs-bin"
        )
        run_with_timer "Rust → $file" "$bin"
        rm -f "$bin"
      else
        echo "❗ Skipping Rust: rustc not found"; echo
      fi
      ;;
    zig)
      if have zig; then
        run_with_timer "Zig → $file" zig run "$file"
      else
        echo "❗ Skipping Zig: zig not found"; echo
      fi
      ;;
    c)
      if have gcc; then
        bin="$prob_dir/$base-c-bin"
        (
          cd "$prob_dir"
          gcc -std=c11 -O2 -pipe -Wall -Wextra "$base.c" -o "$base-c-bin" -lm
        )
        run_with_timer "C (gcc) → $file" "$bin"
        rm -f "$bin"
      else
        echo "❗ Skipping C: gcc not found"; echo
      fi
      ;;
    cpp)
      if have g++; then
        bin="$prob_dir/$base-cpp-bin"
        (
          cd "$prob_dir"
          g++ -std=c++17 -O2 -pipe -Wall -Wextra "$base.cpp" -o "$base-cpp-bin"
        )
        run_with_timer "C++ (g++) → $file" "$bin"
        rm -f "$bin"
      else
        echo "❗ Skipping C++: g++ not found"; echo
      fi
      ;;
  esac
done

if [[ "$found_any" = false ]]; then
  echo "⚠️  No files found for $pid (looked for $base.[${ALL_EXTS[*]}])"
fi
