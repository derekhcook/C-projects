// Derek Cook
// CS 2336
// Lab 13

#include <bits.h>
#include <climits> //for CHAR_BITS

int countOneBits(int num)
{
    if (num == 0) // base case
    {
        return 0;
    }
    else // generaal recursive case
    {
        int lsb = getBit(num, 0); //determine rightmost bit
        num = num >> 1;
        num = setBit(num, sizeof(int) * CHAR_BIT - 1, 0); // sets most significant bit to 0
        return lsb + countOneBits(num);
    }
}
