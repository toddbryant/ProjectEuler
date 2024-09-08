// Project Euler problem 7
// Find the 10,001st prime number

#include <iostream>
#include "PrimeIterator.h"

int main()
{
   Euler::PrimeIterator it(200000); // prime density function suggests ~116,671
   std::cout << *(Euler::PrimeIterator(2) + 10000) << std::endl;
   return 0;
}

