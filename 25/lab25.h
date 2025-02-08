#ifndef LAB25_H
#define LAB25_H

#include <iostream>

using namespace std;

template<typename T>
class Accumulator
{
  // overloaded operator << as a friend
  template<typename U>
  friend ostream& operator<<(ostream& output, const Accumulator<U>& obj);

 public:
  Accumulator(const T& value = T());    // constructor

  // access and update functions
  T getTotal() const;                   // return total
  void addValue(const T& value);        // add (+) value to total

 private:
  T total;                              // data stored by the object
};

#include "lab25.cpp"

#endif
