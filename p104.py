#!/usr/bin/python

# Project Euler Problem 104
# 
# Finds the first Fibonacci number whose first and last nine digits
# are permutations of 123456789.
# Uses modular arithmetic to compute the last nine digits exactly 
# and the golden ratio to compute just the first nine digits of each number.

DIGITS = set(str('123456789'))
def is9Pandigital(n):
    return set(str(n)) == DIGITS

GOLDEN_RATIO = (1+5**0.5)/2

# Start at a 9-digit Fibonacci number
back, back_old, k = 433494437, 267914296, 43
front = back

digits = 16
# Now compute just the first and last nine digits of each Fibonacci number
while not (is9Pandigital(back) and is9Pandigital(int(front / 10**(digits-9)))):
   front *= GOLDEN_RATIO
   if front>10**digits:
      front //= 10
   back, back_old, k = (back + back_old) % 1_000_000_000, back, k + 1

print(k)
