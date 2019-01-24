#ifndef CGL_COLOR_H
#define CGL_COLOR_H

#include "CGL.h"

#include <string>

namespace CGL {

/**
 * Encodes a color via additive red, green, and blue chanel values.
 * Each color chanel value is in the range [0,1]. The alpha value
 * defines the transparency of the color and is also in [0,1].
 */
class Color {
 public:

  // Components.
  float r; /**< value of red chanel   */
  float g; /**< value of green chanel */
  float b; /**< value of blue chanel  */

  // constants
  static const Color White;
  static const Color Black;

  /**
   * Constructor.
   * Initialize from component values.
   * \param r Value of the red chanel.
   * \param g Value of the green chanel.
   * \param b Value of the blue chanel.
   */
  Color( float r = 0, float g = 0, float b = 0 )
      : r( r ), g( g ), b( b ) { }

  /**
   * Constructor.
   * Initialize from array of 8-bit component values (RGB).
   * \param arr Array containing component values.
   */
  Color( const unsigned char* arr );

  // Array-style access
  float& operator[](int k) {
    return (&r)[k];
  }
  const float& operator[](int k) const {
    return (&r)[k];
  }

  // Addition.
  inline Color operator+( const Color& rhs ) const {
    return Color( r + rhs.r, g + rhs.g, b + rhs.b);
  }

  inline Color& operator+=( const Color& rhs ) {
    r += rhs.r; g += rhs.g; b += rhs.b;
    return *this;
  }

  // Vector multiplication.
  inline Color operator*( const Color& rhs ) const {
    return Color( r * rhs.r, g * rhs.g, b * rhs.b);
  }

  inline Color& operator*=( const Color& rhs ) {
    r *= rhs.r; g *= rhs.g; b *= rhs.b;
    return *this;
  }

  // Scalar multiplication.
  inline Color operator*( float s ) const {
    return Color( r * s, g * s, b * s );
  }

  inline Color& operator*=( float s ) {
    r *= s; g *= s; b *= s;
    return *this;
  }

  // comparison
  inline bool operator==( const Color& rhs ) const {
    return r == rhs.r && g == rhs.g && b == rhs.b;
  }

  inline bool operator!=( const Color& rhs ) const {
    return !operator==( rhs );
  }

  /**
   * Construct a Color object from a hexadecimal (8-bit per
   * component) ASCII string.
   * \return Color constructed from the input hex encoding.
   */
  static Color fromHex( const char* s );

  /**
   * Returns a hexadecimal string #rrggbb encoding this color.
   * \return the hexadecimal encoding of the color.
   */
  std::string toHex( ) const;


}; // class Color


// Commutable scalar multiplication.
inline Color operator*( float s, const Color& c ) {
  return c * s;
}

// Prints components.
std::ostream& operator<<( std::ostream& os, const Color& c );

} // namespace CGL

#endif
