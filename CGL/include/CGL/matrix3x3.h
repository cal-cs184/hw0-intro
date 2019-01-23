#ifndef CGL_MATRIX3X3_H
#define CGL_MATRIX3X3_H

#include "CGL.h"
#include "vector3D.h"

#include <iosfwd>

namespace CGL {

/**
 * Defines a 3x3 matrix.
 * 3x3 matrices are extremely useful in computer graphics.
 */
class Matrix3x3 {

  public:

  // The default constructor. Returns identity.
  Matrix3x3(void) { 
    for( int i = 0; i < 3; i++ ) {
      for( int j = 0; j < 3; j++ ) {
          (*this)(i,j) = (i==j) ? 1. : 0.;
      }
    }
  }

  // Constructor for row major form data.
  // Transposes to the internal column major form.
  // REQUIRES: data should be of size 9 for a 3 by 3 matrix..
  Matrix3x3(double * data)
  {
    for( int i = 0; i < 3; i++ ) {
      for( int j = 0; j < 3; j++ ) {
	        // Transpostion happens within the () query.
	        (*this)(i,j) = data[i*3 + j];
      }
    }
  }

  Matrix3x3(double m00, double m01, double m02, 
            double m10, double m11, double m12, 
            double m20, double m21, double m22)
  {
    (*this)(0,0) = m00; (*this)(0,1) = m01; (*this)(0,2) = m02;
    (*this)(1,0) = m10; (*this)(1,1) = m11; (*this)(1,2) = m12;
    (*this)(2,0) = m20; (*this)(2,1) = m21; (*this)(2,2) = m22;
  }

  /**
   * Sets all elements to val.
   */
  void zero(double val = 0.0 );

  /**
   * Returns the determinant of A.
   */
  double det( void ) const;

  /**
   * Returns the Frobenius norm of A.
   */
  double norm( void ) const;

  /**
   * Returns the 3x3 identity matrix.
   */
  static Matrix3x3 identity( void );

  /**
   * Returns a matrix representing the (left) cross product with u.
   */
  static Matrix3x3 crossProduct( const Vector3D& u );

  /**
   * Returns the ith column.
   */
        Vector3D& column( int i );
  const Vector3D& column( int i ) const;

  /**
   * Returns the transpose of A.
   */
  Matrix3x3 T( void ) const;

  /**
   * Returns the inverse of A.
   */
  Matrix3x3 inv( void ) const;

  // accesses element (i,j) of A using 0-based indexing
        double& operator()( int i, int j );
  const double& operator()( int i, int j ) const;

  // accesses the ith column of A
        Vector3D& operator[]( int i );
  const Vector3D& operator[]( int i ) const;

  // increments by B
  void operator+=( const Matrix3x3& B );

  // returns -A
  Matrix3x3 operator-( void ) const;

  // returns A-B
  Matrix3x3 operator-( const Matrix3x3& B ) const;

  // returns c*A
  Matrix3x3 operator*( double c ) const;

  // returns A*B
  Matrix3x3 operator*( const Matrix3x3& B ) const;

  // returns A*x
  Vector3D operator*( const Vector3D& x ) const;

  // divides each element by x
  void operator/=( double x );

  protected:

  // column vectors
  Vector3D entries[3];

}; // class Matrix3x3

// returns the outer product of u and v
Matrix3x3 outer( const Vector3D& u, const Vector3D& v );

// returns c*A
Matrix3x3 operator*( double c, const Matrix3x3& A );

// prints entries
std::ostream& operator<<( std::ostream& os, const Matrix3x3& A );

} // namespace CGL

#endif // CGL_MATRIX3X3_H
