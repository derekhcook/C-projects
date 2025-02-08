// Derek Cook
// Cs 2336
// Lab 30

#include <iostream>
#include <vector>
#include <IntegerSet.h>

using namespace std;

void sieveOfEratosthenes(IntegerSet& prime)
{
    //nested loop

    uint n = prime.size();
    for (uint i = 2; i * i <= n; ++i)
    {
        if(prime.isMember(i))
        {
            for(uint j = i * i; j <= n; j += i)
            {
                prime.reset(j);
            }
        }
    }
}

// overloaded output operator for printing IntegerSet set to
// output stream out

/*friend*/ ostream& operator<<(ostream& out, const IntegerSet& set)
{
    uint i, end = set.size();
    for (i = 0; i < end; ++i)
    {
        if(set.isMember(i))
        {
            out << i << '\n';
        }
    }
    return out;
}
 