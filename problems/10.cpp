/* Project Euler Problem 10 
 * Finds the sum of all primes below 2 000 000.
 * A job for PrimeIterator!
 */

#include <iostream>
#include <numeric>

#include "PrimeIterator.h"

using Euler::PrimeIterator;

int main()
{
   std::cout << std::accumulate(PrimeIterator(2), PrimeIterator(2000000), uint64_t(0));
   return 0;
}

