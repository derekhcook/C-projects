// Derek Cook
// CS 2336
// Lab 15

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <bits.h>
#include <climits>

void printQuaternary (int num, ostream& os)
{
    if(num == 0)
    {
        return;
    }
    else
    {
        int leastSig = getBits(num, 0, 2); //get leftmost bit
        num = num >> 2;
        num = setBit(num, sizeof(int) * CHAR_BIT - 2, 0);
        num = setBit(num, sizeof(int) * CHAR_BIT - 1, 0);
        printQuaternary(num, os);
        os << leastSig;
        
    }
}
