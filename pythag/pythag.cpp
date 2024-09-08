#include "pythag.h"
#include "number_theory.h"

namespace Euler
{

PythagTriple::PythagTriple()
 : a(3), b(4), c(5)
{}

PythagTriple::PythagTriple(uint32_t a, uint32_t b, uint32_t c)
 : a(a), b(b), c(c)
{}

bool getPrimitivePythagTriple(uint32_t a, PythagTriple &triple)
{
   if(a%2 == 1)
      triple = PythagTriple(a, (a*a-1)/2, (a*a+1)/2);
   else 
      triple = PythagTriple(a, (a/2)*(a/2)-1, (a/2)*(a/2)+1);
   return a!=4 && Euler::gcd(triple.a, triple.b) == 1;
}

}; // end namespace Euler
