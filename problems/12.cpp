/* Project Euler Problem #12
 * 
 * Finds the first triangle number with over 500 divisors.
 * The number of divisors in a number can be computed from its prime factors.
 */  

#include <iostream>
#include <map>

#include "PrimeIterator.h"
#include "number_theory.h"

using Euler::PrimeIterator;
using Euler::isqrt;

std::map<int, int> divsCache;
int countDivs(int n);

int main()
{
   PrimeIterator(10000); // initialize the prime table.  we need a better way to do this perhaps.
   int divs = 0, n=1, triangle = 1;
   while(divs <= 500)
   {
      // OK, a fact here.  gcd(n, 2n+1)==1  because n and 2n have all the same divisors
      // so, we count the divisors of n and the divisors of (n+1)/2
      triangle = n * (n+1) / 2;
      if(n%2 == 0)
      {
         divs = countDivs(n/2) * countDivs(n+1);
      }
      else
      {
         divs = countDivs((n+1)/2) * countDivs(n);
      }
      ++n;
   }
   std::cout << triangle << " has " << divs << " divisors." << std::endl;
   
   return 0;
}


/*
 * Counts the number of divisors of n by finding its prime factorization:
 * p1^k1 * p2^k2 * p3^k3 * ... pn^kn
 * and computing (k1+1)(k2+1)(k3+1)
 */
int countDivs(int n)
{
   if(n==1)
      return 1;
   else if(divsCache.count(n))
      return divsCache[n];

   // Check for primes.
   if(*PrimeIterator(n) == n)
   {
      return divsCache[n] = 2;
   }

   int nOrig = n;
   int k = 0;
   PrimeIterator it(isqrt(n));
   // Get first prime divisor of n
   while( (n % *it) != 0)
      --it;

   while( (n % *it) == 0)
   {
      n /= *it;
      ++k;
   }
   return divsCache[nOrig] = (k+1) * countDivs(n);
}
