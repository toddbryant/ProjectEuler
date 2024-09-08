/* Project Euler Problem 4
 *
 * Finds the largest palindrome made from the product of two 3-digit numbers.
 * A product of two 3-digit numbers is between 100^2 = 10000 and 1000^2 = 1000000
 * So, basically we're looking for a 6-digit palindrome ABCCBA
 *
 * = A(100001) + B(10010) + C(1100)
 * = A(11*9091) + B(7*11*13) + C(2*5*11)
 * = 11 [ 9091A + (7*13)B + 10C ]
 * for digit A,B,C.
 */

#include <iostream>
#include "number_theory.h"

// Return true if n (a six-digit palindrome) can be written as a product of 
// two three digit numbers.  We do this by looping backwards from its sqrt,
// searching for a pair of three digit factors.  If one exists, we return true.
bool productOfThrees(int n)
{
   int guess = Euler::isqrt(n);
   while(guess>=100)
   {
      if(n % guess == 0)
      {
         if(n/guess < 1000)
            return true;
         return false; // High factor is only going to get bigger!
      }
      --guess;
   }
}

int main()
{
   int count = 0;
   for(int A=9; A>=0; --A)
   {
      for(int B=9; B>=0; --B)
      {
         for(int C=9; C>=0; --C)
         {
            // A * (11 * 9091) + B * (2*5*7*11*13) + C * (2 * 5 * 11)
            int palindrome = A * 100001 + B * 10010 + C * 1100;
            count++;
            if(productOfThrees(palindrome))
            {
               std::cout << palindrome  
                         << " (" << count << "th palindrome we checked)\n";
               return 0;
            }
         }
      }
   }
   return 0;
}


