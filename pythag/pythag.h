#ifndef PYTHAG_H
#define PYTHAG_H

#include <stdint.h>
#include <vector>
#include "number_theory.h"
/*
 * An iterator to a Pythagorean triple.
 */
namespace Euler
{
   struct PythagTriple
   {
      PythagTriple();
      PythagTriple(uint32_t a, uint32_t b, uint32_t c);
      
      uint32_t a,b,c;
   }; 
   
   /* 
    * Return the primitive pythagorean triple with short leg a.
    * If no such triple exists, return false.
    */ 
   bool getPrimitivePythagTriple(uint32_t a, PythagTriple &triple);
}

#endif
