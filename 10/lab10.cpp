// Derek Cook
// CS 2336
// lab 10

#include <lab10.h>

IntegerSet IntegerSet::operator+(const IntegerSet& rhs) const
{
    IntegerSet myIncrease;
    
    for(uint e = 0; e < N; e++)
    {
        if(isMember(e) || rhs.isMember(e))
            myIncrease = myIncrease + (e);
    }
    return myIncrease;
}

IntegerSet IntegerSet::operator* (const IntegerSet& rhs) const
{
    IntegerSet a;
    
    for(uint e = 0; e < N; e++)
    {
        if(isMember(e) && rhs.isMember(e))
            a = a +(e);
    }
    return a;
}

IntegerSet IntegerSet:: operator- (const IntegerSet& rhs) const
{
    IntegerSet b;
    
    for(uint e = 0; e < N; e++)
    {
        if(isMember(e) && !rhs.isMember(e))
            b = b + (e);
    }
    return b;
}

IntegerSet IntegerSet::operator/ (const IntegerSet& rhs) const
{
    IntegerSet c;
    
    for(uint e = 0; e < N; e++)
    {
        if((isMember(e) && !rhs.isMember(e)) || (!isMember(e) && rhs.isMember(e)))
            c = c + (e);
    }
    return c;
}
