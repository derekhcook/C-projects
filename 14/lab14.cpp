// Derek Cook
// CS 2336
// Lab 14

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <bits.h>
#include <climits>

using namespace std;

// printBinary is a recursive function that writes the binary
// representation of num to output stream os
void printBinary(int num, ostream& os)
{
    if (num == 0)
    {
        return;
    }
    else
    {
        int lsb = getBit(num, 0); //determine rightmost bit
        num = num >> 1;
        num = setBit(num, sizeof(int) * CHAR_BIT - 1, 0);
        printBinary(num, os);
        os << lsb;
    }
}