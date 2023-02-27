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

assert "abcabccbb" "abcabccbb"
assert "bbbbb" "bbbbb"
assert "pwwkew" "pwwkew"

echo OK
