/* Project Euler Problem 17
 * Count the number of letters that would be used if the numbers 1 to 1000
 * were written out in words. 
 * 
 * First realization is that the numbers 1 to 19 
 */


#include <iostream>
#include <string>

int main()
{
   std::string oneToNineteen[20] = {"", "one", "two", "three", "four", "five", "six",
                                    "seven", "eight", "nine", "ten", "eleven", "twelve",
                                    "thirteen", "fourteen", "fifteen", "sixteen", 
                                    "seventeen", "eighteen", "nineteen"};

   std::string twentyToNinety[10] = {"", "", "twenty", "thirty", "forty", 
                              "fifty", "sixty", "seventy", "eighty", "ninety"};

   int total = 0;
   int oneThroughNine = 0;
   int oneThrough99 = 0;
   for(int i=1; i<=9; ++i)
      oneThroughNine += oneToNineteen[i].size();
   oneThrough99 = oneThroughNine;
   for(int i=10;i<=19; ++i)
      oneThrough99 += oneToNineteen[i].size();
   /* Add all the *enties */
   for(int i=2; i<=9; ++i)
      oneThrough99 += 10 * twentyToNinety[i].size() + oneThroughNine;
   total = oneThrough99;
   for(int i=1; i<=9; ++i)
      // 10 for "hundred and", subtract and for the first number
      total += (oneToNineteen[i].size() + 10) * 100 - 3 + oneThrough99;
   total += 11; /* one thousand*/   
   std::cout << total << std::endl;
   return 0;
}
