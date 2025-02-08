//Derek Cook
//CS 2336
//lab06

#include <lab06.h>

IntegerSet IntegerSet::Union(const IntegerSet& otherSet) const
{
    IntegerSet myUnion;

    //Loop through the universe. If e is a member of *this or otherSet
    //Then insert e into myUnion. Do this for the rest as well.
    for (uint e = 0; e < N; e++)
    {
        if(isMember(e) || otherSet.isMember(e))
            myUnion.insertElement(e);
    }

    return myUnion;
}


IntegerSet IntegerSet::intersection(const IntegerSet& otherSet) const
{
    IntegerSet inter;

    for (uint e = 0; e < N; e++)
    {
        if(isMember(e) && otherSet.isMember(e))
            inter.insertElement(e);
    }

    return inter;
}


IntegerSet IntegerSet::difference(const IntegerSet& otherSet) const
{
    IntegerSet dif;

    for (uint e = 0; e < N; e++)
    {
        if(isMember(e) && !otherSet.isMember(e))
            dif.insertElement(e);
    }


    return dif;
}


IntegerSet IntegerSet::symmetricDifference(const IntegerSet& otherSet) const
{
    IntegerSet symDif;

    for (uint e = 0; e < N; e++)
    {
        if((isMember(e) && !otherSet.isMember(e)) || (!isMember(e) && otherSet.isMember(e)))
            symDif.insertElement(e);
    }


    return symDif;
}
