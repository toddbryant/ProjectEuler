# Project Euler Problem 20
# Print the sum of the digits in 100!
# Again, Python irresistible...

print sum(int(x) for x in str(reduce(lambda x, y : x*y, range(1,101), 1)))
