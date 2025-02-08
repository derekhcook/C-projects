// Derek Cook
// CS 2336
// Lab 16


#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <bits.h>
#include <climits>
// printOctal is a recursive function that writes the octal
// representation of num to output stream os
void printOctal(int num, ostream& os)
{
    if (num == 0)
    {
        return;
    }
    else
    {
        int lsb = getBits(num, 0, 3); //determine rightmost bit
        num = num >> 3;
        num = setBit(num, sizeof(int) * CHAR_BIT - 3, 0);
        num = setBit(num, sizeof(int) * CHAR_BIT - 2, 0);
        num = setBit(num, sizeof(int) * CHAR_BIT - 1, 0);
        printOctal(num, os);
        os << lsb;
    }
}