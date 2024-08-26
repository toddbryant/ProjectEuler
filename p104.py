#!/usr/bin/python

# Project Euler Problem 104
# 
# Finds the first Fibonacci number whose first and last nine digits
# are permutations of 123456789.
# Uses modular arithmetic to compute the last nine digits exactly 
# and the golden ratio to compute just the first nine digits of each number.

DIGITS = set('123456789')
def is_9_pandigital(n):
    return set(str(n)) == DIGITS

GOLDEN_RATIO = (1+5**0.5)/2

# 42nd and 41st Fibonacci numbers have 9 digits; start there
last, prev_last, k = 165580141, 102334155, 41
first = last

# Now compute just the first and last nine digits of each Fibonacci number
while not (is_9_pandigital(last) and is_9_pandigital(int(first))):
   first *= GOLDEN_RATIO
   if first > 999_999_999:
      first /= 10
   last, prev_last = (last + prev_last) % 1_000_000_000, last
   k += 1

print(k)
