/* Project Euler Problem #14
 * Given the Collatz sequence:
 *    n -> n/2, n even
 *    n -> 3n+1, n odd
 * Find  
 */

#include <iostream>
#include <vector>

const int SIZE = 1000000;
int sequenceSize(uint64_t n);

int main()
{
   int maxLength = 0, bestN;
   for(int n=2; n<SIZE; ++n)
   {
      int length = sequenceSize(n);
      if(length > maxLength)
      {
         maxLength = length;
         bestN = n; 
      }
   }
   std::cout << bestN << std::endl;
   return 0;
}

int sequenceSize(uint64_t n)
{
   // Map each 1,2,...,1000000 to its sequence distance to one.
   static std::vector<int> cache(SIZE, 0);

   if(n==1)
      return 1;
   else if(n<SIZE && cache[n]!=0)
      return cache[n];
   int distance;
   if(n%2 == 0)
      distance = 1 + sequenceSize(n/2);
   else
      distance = 1 + sequenceSize(3*n + 1);

   if(n<SIZE)
      cache[n] = distance;

   return distance;
}
