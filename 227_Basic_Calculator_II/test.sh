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

assert 7 "3+2*2" 
assert 1 "3/2"
assert 5 "3+5/2" 

echo OK