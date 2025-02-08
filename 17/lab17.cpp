// Derek Cook
// CS 2336
// Lab 17

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <bits.h>
#include <climits>

// printHexadecimal is a recursive function that writes the hexadecimal
// representation of num to output stream os
void printHexadecimal(int num, ostream& os)
{
        if (num == 0)
    {
        return;
    }
    else
    {
        int lsb = getBits(num, 0, 4); //determine rightmost bit
        num = num >> 4;
        num = setBit(num, sizeof(int) * CHAR_BIT - 4, 0);
        num = setBit(num, sizeof(int) * CHAR_BIT - 3, 0);
        num = setBit(num, sizeof(int) * CHAR_BIT - 2, 0);
        num = setBit(num, sizeof(int) * CHAR_BIT - 1, 0);
        printHexadecimal(num, os);
        char lsbHex = lsb + 48;
        if(lsbHex > 57)
            lsbHex += 7;
        os << lsbHex;
    }
}