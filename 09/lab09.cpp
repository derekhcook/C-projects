// Derek Cook
// CS 2336
// Lab 09

#include <lab09.h>

Rational& Rational::operator++()
{
    // add 1 to *this
    
    reduce();
    setNumerator(getNumerator() + getDenominator());
    return *this;
}

Rational Rational::operator++(int)
{
    Rational copyThis = *this;
    ++*this;
    return copyThis;
}

Rational& Rational::operator--()
{
    reduce();
    setNumerator(getNumerator() - getDenominator());
    return *this;
}

Rational Rational::operator--(int)
{
    Rational copyThis = *this;
    --*this;
    return copyThis;
}
