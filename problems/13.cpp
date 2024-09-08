/*
 * Project Euler Problem 13. 
 * Work out the first 10 digits of the sum of the 50 100-digit numbers
 * (saved in hundos.txt).
 */
#include <iterator>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string addNums(std::vector<std::string> nums);

int main()
{
   std::ifstream in("hundos.txt");
   std::string number;

   // Read all weights, fancyman style.
   std::istream_iterator<std::string> start(in);
   std::istream_iterator<std::string> end;
   std::vector<std::string> nums(start, end);
   std::string sum = addNums(nums);

   std::cout << "Sum: " << sum << std::endl;
   std::cout << "First 10: " << std::string(sum,0,10) << std::endl;

   return 0;
}

/* Do long addition! */
std::string addNums(std::vector<std::string> nums)
{
   std::cout << "in addnums, nums.size()=" << nums.size() << std::endl;
   std::string result;
   int offset = 0; // Distance from rightmost digit
   bool didAdd;
   int carry = 0;
   do
   {
      didAdd = false;
      int digSum = carry;
      for(int i=0; i<nums.size(); ++i)
      {
         int len = nums[i].size();
         int digIdx = len - 1 - offset;
         if(digIdx>=0)
         {
            int digit = nums[i][digIdx];
            digSum += digit - '0';
            didAdd = true;
         }
      }
      result = std::string(1, digSum%10 + '0') + result;
      carry = digSum/10;
      ++offset;
   } while(didAdd);
   std::stringstream ss;
   ss << carry;
   result = ss.str() + result;
   return result;
}

