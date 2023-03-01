#!/bin/bash
assert() {
  expected="$1"
  input="$2"

  actual="$(./main "$input")" 

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

assert "abcabccbb" 3
assert "bbbbb" 1
assert "pwwkew" 3

echo OK
