/* Project Euler Problem #9
 * Find the greatest Pythagorean triple with sum 1000
 */

#include <iostream>
#include "pythag.h"

int main()
{
   int a=2;
   while(++a < 1000)
   {
      Euler::PythagTriple triple;
      if(Euler::getPrimitivePythagTriple(a, triple))
      {
         if( 1000 % (triple.a + triple.b + triple.c) == 0 )
         {
            int factor = 1000 / (triple.a + triple.b + triple.c);
            std::cout << factor * factor * factor * triple.a * triple.b * triple.c << std :: endl;
            return 0;
         }
      }
   }
   // shouldn't be here
   return 1;
}
