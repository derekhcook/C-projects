#ifndef LAB10_H
#define LAB10_H

#include <iostream>
#include <bits.h>

using namespace std;

const uint N = 40;

class IntegerSet
{
  // overloaded output operator for printing IntegerSet set to
  // output stream out
  friend ostream& operator<<(ostream& out, const IntegerSet& set);
 public:
  IntegerSet();                           // initializes the set to the empty
                                          //   set
  IntegerSet(const IntegerSet& otherSet); // copy constructor
  ~IntegerSet();                          // destructor
  bool isMember(uint e) const;            // returns true if e is a member of
                                          //   the set and false otherwise
  uint cardinality() const;               // cardinality of a set
  IntegerSet operator+(uint e) const;     // if e is valid and not a member of
                                          //   the set, insert e into set
  IntegerSet operator-(uint e) const;     // if e is valid and a member of
                                          //   the set, delete e from set
  IntegerSet operator-() const;           // complement of a Set
  IntegerSet& operator=(const IntegerSet& rhs); // *this = rhs

  IntegerSet operator+(const IntegerSet& rhs) const; // union
  IntegerSet operator*(const IntegerSet& rhs) const; // intersection
  IntegerSet operator-(const IntegerSet& rhs) const; // difference
  IntegerSet operator/(const IntegerSet& rhs) const; // symmetric diff

 private:
  uint *bitVector;                        // Pointer to dynamically
                                          //   allocated memory
  bool isValid(uint e) const;             // 0 <= e < N
  uint word(uint n) const;                // Determine index within
                                          //   bitVector where n is located
  uint bit(uint n) const;                 // Determine position within
                                          //   bitVector[word(n)]
                                          //   for element n
  void allocateStorage();                 // Calculate # of elements
                                          //   in bitVector to represent
                                          //   elements 0..(N-1) & then
                                          //   allocate storage
};

#endif
