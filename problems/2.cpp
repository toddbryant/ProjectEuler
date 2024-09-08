/* Find the sum of even Fibonacci numbers not exceeding 4million */
/* After 1,1, we get an even Fibonacci number ever 3 terms. */

#include <iostream>

static const int SIZE = 4000000;
int main()
{
   int sum=0, b=1, c=2;
   while(c<SIZE)
   {
      sum += c;
      // next items are b+c, b+2c, 2b+3c
      b += c*2; // Now b+2c
      c = b*2 - c;
      std::cout << c << std::endl;
   }
   std::cout << sum << '\n';
   return 0;
}
