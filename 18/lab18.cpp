// Derek Cook
// CS 2336
// Lab 18

#include <bits.h>
#include <climits>
#include <iomanip>

using namespace std;

void printBase32(int num, ostream& os)
{
    if(num == 0) //base case
    {
        return;
    }
    else
    {
        int lsb = getBits(num, 0, 5); // get leftmost bit
        num = num >> 5;
        num = setBit(num, sizeof(int) * CHAR_BIT - 5, 0);
        num = setBit(num, sizeof(int) * CHAR_BIT - 4, 0);
        num = setBit(num, sizeof(int) * CHAR_BIT - 3, 0);
        num = setBit(num, sizeof(int) * CHAR_BIT - 2, 0);
        num = setBit(num, sizeof(int) * CHAR_BIT - 1, 0);
        printBase32(num, os);
        char base = lsb + 48;
        if(base > 57)
            base += 7;
        os << base;
    }
}