#!/usr/bin/python

# Project Euler Problem 104
# 
# Finds the first Fibonacci number whose first and last nine digits
# are permutations of 123456789.
# Uses modular arithmetic to compute the last nine digits exactly and
# the golden ratio to compute just the first nine digits of each number.

from math import log, sqrt

def is9Pandigital(n):
   # the 2^k binary digit of digitFlags is 1 if we have observed digit k
   digitFlags = 0
   for ctr in range(0,10):
      digitFlags = digitFlags | (1 << (n%10))
      n = n/10
   return digitFlags == 1023


GOLDEN_RATIO = (1+sqrt(5))/2

# Generate a big Fibonacci number so the golden ratio is a good approximation
f, fOld, k = 1, 0, 1
while f < 10**8:
   f, fOld, k = fOld+f, f, k+1

# Now compute just the first and last nine digits of each Fibonacci number
lastNine, lastNineOld, firstNine ,firstNineOld = f, fOld, f, fOld
while not (is9Pandigital(lastNine) and is9Pandigital(int(firstNine))):
   firstNine, firstNineOld = firstNine * GOLDEN_RATIO, firstNine
   if firstNine>10**9:
      firstNine = firstNine/10
   lastNine, lastNineOld = (lastNine + lastNineOld) % 10**9, lastNine
   k = k+1

print k
