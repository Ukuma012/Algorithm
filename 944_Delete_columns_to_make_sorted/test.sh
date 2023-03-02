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

assert 1 "cba daf ghi" 
assert 0 "a b" 
assert 3 "zyx wvu tsr" 
assert 0 "char char char"

echo OK