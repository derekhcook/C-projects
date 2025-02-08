// Derek Cook
// CS 2336
// Lab 11

#include <lab11.h>

bool IntegerSet::operator==(const IntegerSet& rhs) const // Test for equality
{
    

    for (uint e = 0; e < N; e++)
    {
        if(isMember(e) != rhs.isMember(e))
            return false;
    }

    return true;
}
bool IntegerSet::operator<=(const IntegerSet& rhs) const // Subset
{
    for (uint e = 0; e < N; e++)
    {
        if(isMember(e))
        {
            if(!rhs.isMember(e))
            {
                return false;
            }
        }
    }
    return true;
}
bool IntegerSet::operator< (const IntegerSet& rhs) const // Proper Subset
{
    if(*this == rhs)
        return false;
    if(*this <= rhs)
        return true;

    else
        return false;

}