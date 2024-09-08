#ifndef EULER_H
#define EULER_H

namespace Euler
{
   /* ======================
    * = TEMPLATE FUNCTIONS =
    * ====================== */

   // Return the greatest integer <= sqrt(n)
   template<typename T>
   int isqrt(T n)
   {
      T oldGuess = n;
      T guess = n/2;
      while(abs(oldGuess-guess) > 1)
      {
         oldGuess = guess;
         guess = (oldGuess + n/oldGuess)/2;
      }
      return static_cast<int>(guess);
   }

   // Return the absolute value of n
   template<typename T>
   T abs(T n)
   {
      return n < 0 ? -n : n;
   }

   // Return the greatest common divisor of a and b
   template<typename T>
   T gcd(T a, T b)
   {
      T temp;
      while(b!=0)
      {
         temp = a;
         a = b;
         b = temp % b;
      }
      return a;
   }

   // Return x and y such that ax+by=gcd(a,b)
   template<typename T>
   std::pair<T, T> extended_euclidean(T a, T b)
   {
      if(b==0) 
         return std::make_pair(1,0);
      T q = a/b;
      T r = a%b;
      std::pair<T, T> st = extended_euclidean(b, r);
      T s = st.first;
      T t = st.second;
      return std::make_pair(t, s-q*t);
   }
   
   template<typename T>
   T reverse(T n)
   {
      T reversed = 0;
      while(n)
      {
         reversed = reversed * 10 + (n % 10);
         n /= 10;
      } 
      return reversed;
   }

   // Return true if type is a palindrome
   template<typename T>
   bool isPalindrome(T n)
   {
      return n == reverse(n);
   }

}

#endif
