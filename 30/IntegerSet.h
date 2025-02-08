#ifndef INTEGER_SET
#define INTEGER_SET

#include <iostream>
#include <vector>

using namespace std;

class IntegerSet
{
  // overloaded output operator for printing IntegerSet set to
  // output stream out
  friend ostream& operator<<(ostream& out, const IntegerSet& set);
 public:
  IntegerSet(uint n = 40);                // default constructor; set consists
                                          //   0..(n-1); set N to n; make set
                                          //   empty
  bool isMember(uint e) const;            // returns true if e is a member of
                                          //   the set and false otherwise
  IntegerSet& set(uint e);                // if e is valid and not a member of
                                          //   the set, insert e into set
  IntegerSet& reset(uint e);              // if e is valid and a member of
                                          //   the set, delete e from set
  uint size() const;                      // returns N, the # of possible
                                          //   integers in set  
 private:
  uint N;                                 // # of integers in set: 0..(N-1)
  vector<uint> bitVector;                 // bit vector
  bool isValid(uint e) const;             // 0 <= e < N
  uint word(uint n) const;                // Determine index within
                                          //   bitVector where n is located
  uint bit(uint n) const;                 // Determine position within
                                          //   bitVector[word(n)]
                                          //   for element n
};

#endif
