// Derek Cook
// cs 2336
// lab 02

#include <lab02.h>
#include <cmath>

Rational::Rational()                          // default constructor
    : Rational(0, 1)
{ }

Rational::Rational(int num, int denom)        // additional constructor
{
    setNumerator(num);
    setDenominator(denom);
}

void Rational::setNumerator(int num)          // set numerator to num
{
    data.first = num;
}

void Rational::setDenominator(int denom)      // set denominator to denom
{
    data.second = (denom == 0) ? 1 : denom;
}

int Rational::getNumerator() const
{
    return data.first;
}

int Rational::getDenominator() const          // return denominator
{
    return data.second;
}

void Rational::reduce()                       // Reduce to lowest terms an
{
    int myGCD = gcd(getNumerator(), getDenominator());
    
    if (getDenominator() < 0)
        myGCD = -myGCD;
    
    setNumerator(getNumerator() / myGCD);
    setDenominator(getDenominator() / myGCD);
}

int Rational::gcd(int m, int n) const         // returns the greatest common diviser of m and
{
    if (m == 0)
        return abs(n);
    else if (n == 0)
        return abs(m);
    else //use euclid's algorithm to find gcd
    {
        m = abs(m);
        n = abs(n);
        int rem = m % n;
        
        while (rem > 0)
        {
            m = n;
            n = rem;
            rem = m % n;
        }
        return n;
    }
}
