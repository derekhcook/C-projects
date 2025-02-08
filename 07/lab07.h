#ifndef LAB07_H
#define LAB07_H

#include <iostream>

using namespace std;

class Rational
{
  // overloaded input operator initializes Rational rat from input stream in
  friend istream& operator>>(istream& in, Rational& rat);
  // overloaded output operator prints Rational rat to output stream out
  friend ostream& operator<<(ostream& out, const Rational& rat);
 public:
  Rational();                                     // default constructor
  Rational(int num, int denom);                   // additional constructor
  void setNumerator(int num);                     // set numerator to num
  void setDenominator(int denom);                 // set denominator to denom
  int getNumerator() const;                       // returns numerator
  int getDenominator() const;                     // returns denominator
  void reduce();                                  // reduce to lowest terms
                                                  //   and normalize
  Rational multiplicativeInverse() const;         // returns multiplicative
                                                  //   inverse of *this

  Rational& operator=(const Rational& rhs);       // *this = rhs;
  Rational operator+(const Rational& addend) const;// returns *this + addend
  Rational operator-() const;                     // returns -(*this)
  Rational operator-(const Rational& subtrahend) const;// returns *this - subtrahend
  Rational operator*(const Rational& multiplicand) const;// returns *this * multiplicand
  Rational operator/(const Rational& divisor) const;// returns *this / divisor

  bool operator==(const Rational& rhs) const;     // *this == rhs
  bool operator!=(const Rational& rhs) const;     // *this != rhs
  bool operator< (const Rational& rhs) const;     // *this <  rhs
  bool operator<=(const Rational& rhs) const;     // *this <= rhs
  bool operator> (const Rational& rhs) const;     // *this >  rhs 
  bool operator>=(const Rational& rhs) const;     // *this >= rhs

 private:
  pair<int, int> data;                            // member first -> numerator
                                                  // member second -> denominator
  int gcd(int m, int n) const;                    // returns the greatest
                                                  //   common divisor of m
                                                  //   and n
  int lcm(int m, int n) const;                    // returns the least common
                                                  //   multiple of m and n
};

#endif
