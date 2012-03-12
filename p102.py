#!/usr/bin/python

# Project Euler Problem 102
# Reads a list of 1,000 triangles and counts the number that contain (0,0)

# Make a linear vector function r(t) = <Xa-Xa*t, Ya-Ya*t>
# When t=0, r(t) is at A; when t=1 r(t) is at (0,0)
# Find the value of t at which r(t) intersects line BC
# The triangle contains the origin iff this point is between B and C and t>=1
#
# Basically, if O is in the triangle, a ray from A to O must hit O, then BC.
def containsOrigin(Xa, Ya, Xb, Yb, Xc, Yc):
   """Returns true if the triangle made by these coordinates contains (0,0)"""
   if Xa==0 and Ya==0: # A is the origin
      return true
   if Xb==Xc: # BC is vertical
      if Xa==0:
         return false
      t = 1 - Xb/Xa
      yInt = Ya-Ya*t
      return yInt >= min(Yb, Yc) and yInt <= max(Yb,Yc) and t>=1
   # Otherwise, we have the normal case: BC isn't vertical
   num = (Yc-Yb)*(Xa-Xb)/(Xc-Xb) - (Ya-Yb)
   denom = (Yc-Yb)*Xa/(Xc-Xb) - Ya
   t = num/denom
   xInt = Xa-Xa*t
   return xInt >= min(Xb, Xc) and xInt <= max(Xb,Xc) and t>=1

count = 0
f = open("triangles.txt", "r")
for line in f.readlines():
   vals = line.split(",")
   if containsOrigin(float(vals[0]), float(vals[1]), float(vals[2]), float(vals[3]), float(vals[4]), float(vals[5])):
      count = count + 1
print count
