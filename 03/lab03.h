#ifndef LAB03_H
#define LAB03_H

#include <iostream>
#include <utility>

using namespace std;

class Rational
{
 public:
  Rational();                                     // default constructor
  Rational(int num, int denom);                   // additional constructor
  void setNumerator(int num);                     // set numerator to num
  void setDenominator(int denom);                 // set denominator to denom
  int getNumerator() const;                       // returns numerator
  int getDenominator() const;                     // returns denominator
  void reduce();                                  // Reduce to lowest terms
                                                  //   and normalize
  Rational add(const Rational& addend) const;     // Addition
  Rational additiveInverse() const;               // Returns the additive
                                                  //   inverse
  Rational subtract(const Rational& subtrahend) const; // Subtraction
  Rational multiply(const Rational& multiplicand) const; // Multiplication
  Rational multiplicativeInverse() const;         // Returns the 
                                                  //   multiplicative inverse
  Rational divide(const Rational& divisor) const;   // Division
  ostream& print(ostream& os) const;              // Print Rational to output
                                                  //   stream
  istream& read(istream& is);                     // Read Rational from input
                                                  //   stream
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
