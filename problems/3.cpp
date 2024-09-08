#include "PrimeIterator.h"
#include "number_theory.h"

#include <iostream>

int main()
{
   const uint64_t x = 600851475143l;

   Euler::PrimeIterator it(Euler::isqrt(x));
   while(x % *--it);
   std::cout << *it << std::endl;

   return 0;
}

