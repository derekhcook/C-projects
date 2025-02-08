// Derek Cook
// CS 2336
// Lab 03

#include <lab03.h>
#include <cmath> // for abs

Rational Rational::add(const Rational& addend) const     // Addition
{
    Rational sum;
    int myLCM = lcm(getDenominator(), addend.getDenominator());
    int newLeftNumerator = myLCM / getDenominator() * getNumerator();
    int newRightNumerator = myLCM /addend.getDenominator() * addend.getNumerator();
    
    sum.setNumerator(newLeftNumerator + newRightNumerator);
    sum.setDenominator(myLCM);
    sum.reduce();
    
    return sum;
}
Rational Rational::additiveInverse() const               // Returns the additive
{
    return Rational(getNumerator() * -1, getDenominator());
}
Rational Rational::subtract(const Rational& subtrahend) const // Subtraction
{
    return add(subtrahend.additiveInverse());
}
Rational Rational::multiply(const Rational& multiplicand) const // Multiplication
{
    Rational sum;
    sum.setNumerator(getNumerator() * multiplicand.getNumerator());
    sum.setDenominator(getDenominator() * multiplicand.getDenominator());
    sum.reduce();
    
    return sum;
}
Rational Rational::multiplicativeInverse() const         // Returns the multiplicitive inverse
{
    Rational myInverse = *this;
    myInverse.setNumerator(getDenominator());
    myInverse.setDenominator(getNumerator());
    
    return myInverse;
}
Rational Rational::divide(const Rational& divisor) const   // Division
{
    Rational sum;
    sum.setDenominator(getDenominator() * divisor.getNumerator());
    sum.setNumerator(getNumerator() * divisor.getDenominator());
    sum.reduce();
    return sum;
}
ostream& Rational::print(ostream& os) const              // Print Rational to output
{
    os << getNumerator() << '/' << getDenominator();
    return os;
}
istream& Rational::read(istream& is)                     // Read Rational from input stream
{
    int num = 0;
    int denom = 1;
    
    is >> num >> denom;
    setNumerator(num);
    setDenominator(denom);
    
    return is;
}
int      Rational::lcm(int m, int n) const                    // returns the least common multiple of m and n
{
    if (m == 0 && n == 0)
        return 0;
    else
        return abs(m * n) / gcd(m, n);
}
