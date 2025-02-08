// Derek Cook
// CS 2336
// Lab 08

#include <lab08.h>

// overloaded output operator for printing IntegerSet set to
// output stream out

/*friend*/ostream& operator<<(ostream& out, const IntegerSet& set)
{
    // print function lab 04

    if (set.cardinality() == 0) //then the set is empty
    {
        out << static_cast<char>(216) << endl;
    }
    else //*this has at least one member
    {
        out << '{';
        //loop through the universe
        //if e is a member then print e
        uint charCount = 0;
        
        
        for (uint e = 0; e < N; ++e)
        {
            if (set.isMember(e))
            {
               if(charCount != 0)
               {
                   out << ',';
               }
                out << e;
                charCount++;
            }
        }
        out << '}' << endl;
    }
    
    return out;
}

IntegerSet IntegerSet::operator+(uint e) const     // if e is valid and not a member of the set, insert e into set
{
    IntegerSet temp(*this);
    
    // setBit:  return value with bit n set to v (0 or 1).
    //unsigned int setBit(unsigned int word, int n, unsigned int v);
    
    if (isValid(e) && !isMember(e))
    {
        uint myWord = bitVector[word(e)];
        int myN = bit(e);
        
        temp.bitVector[word(e)] = setBit(myWord, myN, 1);
    }
    return temp;
}
IntegerSet IntegerSet::operator-(uint e) const     // if e is valid and a member ofthe set, delete e from set
{
    IntegerSet temp(*this);

    
    
    if (isValid(e) && isMember(e))
    {
        //delete [] bitVector;

        uint myWord = bitVector[word(e)];
        int myN = bit(e);
    
        temp.bitVector[word(e)] = setBit(myWord, myN, 0);
    }
    

    return temp;
}
IntegerSet IntegerSet::operator-() const           // complement of a Set
{
    IntegerSet myCompl;
    
    for(uint e = 0; e < N; e++)
    {
        if(!isMember(e))
            myCompl = myCompl + e;
    }
    return myCompl;

}
IntegerSet& IntegerSet::operator=(const IntegerSet& rhs) // *this = rhs;
{
    if (this != &rhs)//avoid self assignment
    {
        for (uint e = 0; e < N; ++e)
        {
            /*
            if (rhs.isMember(e))
                *this = *this + e;
            else
                *this = *this - e;
            */

            uint myWord = bitVector[word(e)];
            int myN = bit(e);
        
            bitVector[word(e)] = setBit(myWord, myN, rhs.isMember(e));


        }
    }
    return *this;
}