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

assert 2 "|*e*et|c**o|*de|" 
assert 0 "iamprogrammer" 
assert 5 "yo|uar|e**|b|e***au|tifu|l"
echo OK