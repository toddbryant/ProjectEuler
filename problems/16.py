'''
 Project Euler Problem 16
 Count the sum of the digits of 2^1000
 Python is just too tasty for this
'''
if __name__ == '__main__':
   print sum(int(digit) for digit in str(2**1000))
