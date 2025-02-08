#ifndef LAB46_H
#define LAB46_H

#include <iostream>
#include <string>
#include <deque>

using namespace std;

typedef enum {NEGATIVE, ZERO, POSITIVE} Sign;

bool isInt(string s);

class BigInt
{
  friend ostream& operator<<( ostream& output, const BigInt& );
  friend istream& operator>>( istream& input, BigInt& );
 public:
  BigInt();                                      // constructor; digits = 0
  BigInt( int num );                             // constructor; digits = num
  BigInt( const string str );                    // constructor; digits = str
  BigInt( const BigInt& other );                 // copy constructor

  bool    operator==( const BigInt& rhs ) const; // Equality
  bool    operator< ( const BigInt& rhs ) const; // Less Than

  BigInt  operator+ ( const BigInt& rhs ) const; // Addition
  BigInt  operator- ( const BigInt& rhs ) const; // Subtraction

 private:
  Sign sign;                                     // Sign of #
  deque<char> digits;                            // Deque of digits of #
};

#endif
