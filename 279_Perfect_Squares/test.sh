#!/bin/bash
assert() {
  expected="$1"
  input="$2"

  actual="$(./main $input)" 

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

assert 3 12
assert 2 13 

echo OK