#!/usr/bin/python

# Project Euler Problem 101
# This problem is a bit complicated. Its explanation is best left to the source:
# http://projecteuler.net/problem=101
#
# My strategy is based on the fact that finding an OP of degree n requires
# solving n+1 linear equations for n+1 unknowns.  I wrote a row reduction
# function that takes advantage of the fact that in this particular problem,
# all of the coefficient vectors will contain positive integers, be linearly
# independent and the solutions will always be integers.

from eulerUtils import lcm, gcd

def solve(matrix):
   """Row reduces an n x (n+1) matrix of positive integers"""
   numRows = len(matrix)
   for pivotCol in range(0, numRows):
      # Find the LCM of the values in this column
      thislcm = 1
      for row in matrix:
         if row[pivotCol]!=0:
            thislcm = lcm(thislcm, row[pivotCol])
      # Multiply each row by thislcm/row[pivotCol]
      for rowNum in range(0, numRows):
         mult = thislcm / matrix[rowNum][pivotCol]
         matrix[rowNum] = [elem * mult for elem in matrix[rowNum]]

      # Subtract row pivotCol from all other rows
      for rowNum in range(0, numRows):
         if rowNum == pivotCol:
            continue
         for column in range(0, numRows+1):
            matrix[rowNum][column] = matrix[rowNum][column] - matrix[pivotCol][column]
      
   return [matrix[rowNum][numRows] / matrix[rowNum][rowNum] for rowNum in range(0, numRows)]

def u(n):
   return 1 - n + n**2 - n**3 + n**4 - n**5 + n**6 - n**7 + n**8 - n**9 + n**10

def evaluateOP(coeffs, x):
   sum = 0
   for n in range(0, len(coeffs)):
      sum = sum + coeffs[len(coeffs)-n-1] * x**n
   return sum

FITsum = 0
# Find approximating polynomials of degree 0-9, and calculate degree 10 for fun
for n in range (1, 12):
   # generate matrix
   matrix = [];
   for rowNum in range(1, n+1):
      row = [u(rowNum)]
      for power in range (0, n):
         row.insert(0, rowNum**power)
      matrix.append(row)

   # Compute the OP coefficients
   coeffs = solve(matrix)

   # Print the OP
   print 'OP(%d, n) = ' % (len(matrix)),
   for n in range(0, len(coeffs)):
      coeffStr = str(abs(coeffs[n]))
      power = len(coeffs) - 1 - n
      if power>0 and coeffStr=='1':
	 coeffStr = ''
      if power==0:
	 print coeffStr
      else:
         if power==1:
            print '%sn' % coeffStr,
         else:
            print '%sn^%d' % (coeffStr, power),
         if(coeffs[n+1] >= 0):
            print '+',
         else:
            print '-',
   # Print the sequence this OP generates
   for x in range(1, len(matrix) + 1):
      print '%d,' % (evaluateOP(coeffs, x)),
   nextTerm = evaluateOP(coeffs, len(matrix)+1)
   print nextTerm,
   if nextTerm != u(len(matrix) + 1):
      print '<======= FIT'
      FITsum = FITsum + nextTerm
   else:
      print '(that\'s correct)'
   print '\n'

print 'The sum of FITs was %d.' % (FITsum)
