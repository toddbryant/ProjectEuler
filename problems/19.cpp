/* Project Euler Problem 19
 * Count the number of Sundays that fell on the first of the month between
 * 1/1/1901 and 12/31/2000.
 * 
 * Leap years occur on any year divisible by 4, but ONLY on centuries divisible
 * by 4 (which happens to be irrelevant for this range).
 *
 * 1/1/1901 was a Monday.
 */

#include <iostream>

// Store the number of days in each month, indexed 1-12.
int daysInMonth[13] = {0, 31, 28 /*feb*/, 31, 30 /*apr*/, 31, 30 /*june*/, 
                       31, 31, 30 /*sept*/, 31, 30 /*nov*/, 31};

int main()
{
   int dayOfWeek = 2; // 1 Jan 1900 was Monday, then there were 365%7=1 days.
   int suncount = 0;
   for(int year=1901; year<=2000; ++year)
   {
      for(int month=1; month<=12; ++month)
      {
         if(dayOfWeek==0)
            suncount++;
         // Advance to first of next month
         int leap = ( (month==2) && ((year%4)==0) ) ? 1 : 0;
         dayOfWeek = (dayOfWeek + daysInMonth[month] + leap) % 7;
      }
   }
   std::cout << suncount << std::endl;

   return 0;
}
