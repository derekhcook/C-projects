//Derek Cook
//CS 2336
//Lab 05
#include <lab05.h>

bool Rational::isEqualTo(const Rational& other) const
{
    int myLCM = lcm(getDenominator(), other.getDenominator());
    int newLeftNumerator = myLCM / getDenominator() * getNumerator();
    int newRightNumerator = myLCM / other.getDenominator() * other.getNumerator();

    return newLeftNumerator == newRightNumerator;

}


bool Rational::isNotEqualTo(const Rational& other) const
{
    return !isEqualTo(other);
}


bool Rational::isLessThan(const Rational& other) const
{
    int myLCM = lcm(getDenominator(), other.getDenominator());
    int newLeftNumerator = myLCM / getDenominator() * getNumerator();
    int newRightNumerator = myLCM / other.getDenominator() * other.getNumerator();

    return newLeftNumerator < newRightNumerator;
}


bool Rational::isLessThanOrEqualTo(const Rational& other) const
{
    return isLessThan(other) || isEqualTo(other);
}


bool Rational::isGreaterThan(const Rational& other) const
{
    return !((isEqualTo(other)) || (isLessThan(other)));
}


bool Rational::isGreaterThanOrEqualTo(const Rational& other) const
{
    return !isLessThan(other);
}
