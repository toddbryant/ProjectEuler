/* Project Euler Problem #21
 * 
 * Finds the sum of all amicable numbers below 10000.
 * Amicable numbers are pairs satisfying a = d(d(a)
 * where d(a) returns the sum of all proper divisors of a.
 */  

#include <iostream>
#include <map>

#include "PrimeIterator.h"

using Euler::PrimeIterator;

std::vector<int> sumCache(10001, 0);

int sumDivs(int n);

int main()
{
   PrimeIterator(10000); // initialize the prime table.  we need a better way to do this perhaps.
   for(int i=2; i<10000; ++i)
   {
      
   }
   std::cout << triangle << " has " << divs << " divisors." << std::endl;
   
   return 0;
}


/*
 * Counts the number of divisors of n by finding its prime factorization:
 * p1^k1 * p2^k2 * p3^k3 * ... pn^kn
 * and computing (k1+1)(k2+1)(k3+1)
 */
int sumDivs(int n)
{
   if(n==1)
      return 0;
   else if(divsCache[n] != 0)
      return divsCache[n];

   // Check for primes.
   if(*PrimeIterator(n) == n)
   {
      return divsCache[n] = 1;
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
   return sumCache[nOrig] = *it + sumDivs(n);
}
