#ifndef PRIME_ITERATOR_H
#define PRIME_ITERATOR_H

#include <vector>

namespace Euler
{
   class PrimeIterator
   {
      public:
         // Return an iterator to largest prime less than or equal to n
         PrimeIterator(size_t n);
         int            operator*  () const;
         PrimeIterator& operator++ ();
         PrimeIterator& operator-- ();
         PrimeIterator  operator+  (int);
         bool           operator== (const PrimeIterator& rhs) const;
         bool           operator!= (const PrimeIterator& rhs) const;
         bool           operator<  (const PrimeIterator& rhs) const;

      private:
         size_t index;

         static size_t maxN; // Maximum value of n we have ever created a PI for.
                             // Sometimes this value is between our max prime and the next prime.
         static std::vector<int> primes;
         static std::vector<bool> is_prime;

         void extendTable(int n);
         void getPrimeSieve(int n);
   };
}

#endif
