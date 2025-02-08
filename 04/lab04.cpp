// Derek Cook
// Cs 2336
//Lab 04

#include <lab04.h>
#include <set>
#include <iostream>
#include <string>
using namespace std;
//delete func 12:02
IntegerSet::IntegerSet()                           // initializes the set to the empty set //done
{
    allocateStorage();
    
    // loop through the universe (0,1,2 ..., (N-1))
    // Make each element contain a 0 bit
    for (uint e = 0; e < N; ++e)
    {
        deleteElement(e);
    }
}
IntegerSet::IntegerSet(const IntegerSet& otherSet) // copy constructor //model after asbove
{
    allocateStorage();
    
    for (uint e = 0; e < N; ++e)
    {
        bitVector[e] = otherSet.bitVector[e];
    }
    
    
}
IntegerSet::~IntegerSet()                          // destructor //done
{
    delete [] bitVector;
}
// returns true if e is a member of the set and false otherwise
bool       IntegerSet::isMember(uint e) const            // returns true if e is a member of the set and false otherwise //done
{
        //getBit: get value of bit n in word.
        // unsigned int getBit (unsigned int word, int n);
    if (isValid(e))
    {
        uint myWord = bitVector[word(e)];
        int myN = bit(e);
        
        return getBit(myWord, myN);
    }
    
    return false;
    
}
uint       IntegerSet::cardinality() const               // cardinality of a set
{
    uint count = 0;
    
    // Loop through the universe (0, 1, 2, ..., (N-1)) and ask if
    // e is a member. if so, increment count.
    for (uint e = 0; e < N; ++e)
    {
        if (isMember(e))
        {
            count++;
        }
    }
    
    
    return count;
}
void       IntegerSet::insertElement(uint e)             // if e is valid and not a member of the set, insert e into set //done
{
    // setBit:  return value with bit n set to v (0 or 1).
    //unsigned int setBit(unsigned int word, int n, unsigned int v);
    
    if (isValid(e) && !isMember(e))
    {
        uint myWord = bitVector[word(e)];
        int myN = bit(e);
        
        bitVector[word(e)] = setBit(myWord, myN, 1);
    }
}
void       IntegerSet::deleteElement(uint e)             // if e is valid and a member of the set, delete e from set
{
    for (uint e = 0; e < N; ++e)
    {
        if (isValid(e) && isMember(e))
        {
            //delete [] bitVector;
            uint myWord = bitVector[word(e)];
            int myN = bit(e);
            
            bitVector[word(e)] = setBit(myWord, myN, 0);
        }
    }
}
IntegerSet IntegerSet::complement() const          // complement of a Set
{
    IntegerSet myCompl;
    
    for(uint e = 0; e < N; e++)
    {
        if(!isMember(e))
            myCompl.insertElement(e);
    }
    return myCompl;
}

ostream&   IntegerSet::print(ostream& os) const
{
    if (cardinality () == 0) //then the set is empty
    {
        os << static_cast<char>(216) << endl;
    }
    else //*this has at least one member
    {
        os << '{';
        //loop through the universe
        //if e is a member then print e
        uint charCount = 0;
        
        
        for (uint e = 0; e < N; ++e)
        {
            if (isMember(e))
            {
               if(charCount != 0)
               {
                   os << ',';
               }
                os << e;
                charCount++;
            }
        }
        os << '}' << endl;
    }
    
    return os;
}
bool       IntegerSet::isValid(uint e) const             // 0 <= e < N
{
    return 0 <= e && e < N;
}
