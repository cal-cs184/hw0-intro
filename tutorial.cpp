// A simple program that computes the square root of a number

// For the Windows folks to properly use cmath / math.h
#define _USE_MATH_DEFINES

// Library for sqrt(), M_PI, and other mathematical goodies
#include <math.h>

// For fprintf, in, out
#include <stdio.h>
#include <stdlib.h>

// Our included library classes
#include "vector2D.h"

// To avoid having to type out the library name, 
// CGL::Vector2D instead of Vector2D
using namespace CGL;

int main(int argc, char* argv[])
{


  Vector2D a = Vector2D(atof(argv[1]), atof(argv[2]));
  Vector2D b = Vector2D(atof(argv[3]), atof(argv[4]));
  Vector2D result = 1.0 * dot(a, b) / a.norm2() * a;

  fprintf(stdout, "The projection of b onto a is %g , %g\n", result.x, result.y);

  
  return 0;
}
