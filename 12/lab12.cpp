// Derek Cook
// CS 2336
// Lab 12

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void insertComma(unsigned long num, ostream& os)
{
    if(num < 1000)
    {
        os << num;
    }
    else
    {
        //recurse first then print
        insertComma(num/1000, os);

        char ch = os.fill();
        os << ',' << setw(3) << setfill('0') << num % 1000;
        os.fill(ch);
    }
}
