#include "PrimeIterator.h"

#include <iostream>
#include <algorithm>

namespace Euler
{
   std::vector<int> PrimeIterator::primes(1, 2); // Initialize with {2}
   std::vector<bool> PrimeIterator::is_prime;

   void PrimeIterator::extendTable(int n)
   {
      getPrimeSieve(n);
      int i = primes.back() + 1;
      while(i<=n)
      {
         if(is_prime[i])
         {
            primes.push_back(i);
         }
         ++i;
      }
   }

   void PrimeIterator::getPrimeSieve(int n)
   {
      // TODO: We can make this function much more efficient when resizing.
      //       There is no need to clear out all the old 1s and 0s; they're correct
      //       also, we only need to loop above the old table size.
      // Need to initialize, or resize, the vector
      if(n > is_prime.size())
      {
         is_prime.reserve(n);

         // Initialize with 1s
         for(int i=2; i<=n; ++i) is_prime[i] = true;

         for(int i=2; i<=n; ++i)
         {
            if(is_prime[i])
            {
               for(int p=2*i; p<=n; p+=i)
               {
                  is_prime[p] = 0;
               }
            }
         }
      }
   }

   PrimeIterator::PrimeIterator(size_t n)
   {
      // TODO: error if n<2?
      if(!primes.empty() && n<=primes.back()) 
      {
         std::vector<int>::iterator it =
            std::lower_bound(primes.begin(), primes.end(), n);
         index = std::distance(primes.begin(), it);
      }
      else
      {
         extendTable(n);
         if(is_prime[n])
         {
            index = primes.size() - 1;
         }
         else
         {
            index = primes.size(); // TODO: See **
         }
      }
   }

   int PrimeIterator::operator*() const
   {
      if(index==primes.size()) // TODO: ** I think this is a way to handle an
                               //          initial call to PrimeIterator(6)...right?
         return primes.back();
      return primes[index];
   }

   PrimeIterator& PrimeIterator::operator++()
   {
      // TODO: over bounds exception?
      ++index;
   }

   PrimeIterator PrimeIterator::operator+(int distance)
   {
      // FIXME: need to extend the table sometimes here! slightly annoying
      //        we'll use the prime numebr theorem to get an upper bound we think
      return PrimeIterator(primes[index + distance]);
   }

   PrimeIterator& PrimeIterator::operator--()
   {
      // TODO: over bounds exception?
      --index;
   }

   
   // TODO: As it stands, PrimeIterator(6) == PrimeIterator(7)
   //       but they dereference differnetly.  not what we want.
   bool PrimeIterator::operator==(const PrimeIterator& rhs) const
   {
      return index == rhs.index;
   }

   bool PrimeIterator::operator!=(const PrimeIterator& rhs) const
   {
      return index != rhs.index;
   }

   bool PrimeIterator::operator< (const PrimeIterator& rhs) const
   {
      return index < rhs.index;
   }
}
