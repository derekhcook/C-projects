/*
 * Functions to get and set bit values.  All assume suitable parameters.
 * Reference:  "The Joy Of C," 3rd ed., pp. 152-164
 */

#ifndef BITS_H
#define BITS_H

#include <fstream>

using namespace std;

// getBit:  get value of bit n in word.
unsigned int getBit(unsigned int word, int n);

// setBit:  return value with bit n set to v (0 or 1).
unsigned int setBit(unsigned int word, int n, unsigned int v);

// getBits: get value of k bits starting at bit position n in word.
unsigned int getBits(unsigned int word, int n, int k);

// setBits: return value with k bits starting at bit position n assigned v.
unsigned int setBits(unsigned int word, int n, int k, unsigned int v);

#endif
