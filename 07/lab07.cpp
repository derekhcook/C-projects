// Derek Cook
// CS 2336
// Lab 07

#include <lab07.h>

// overloaded input operator initializes Rational rat from input stream in
/*friend*/ istream& operator>>(istream& in, Rational& rat)
{
    int numer, denom;

    in >> numer >> denom;

    if (!in)
    {
        numer = 0;
        denom = 1;
    }
    rat.setNumerator(numer);
    rat.setDenominator(denom);

    return in;

}

// overloaded output operator prints Rational rat to output stream out
/*friend*/ ostream& operator<<(ostream& out, const Rational& rat)
{
    out << rat.getNumerator() << "/" << rat.getDenominator();
    return out;
}

Rational& Rational::operator=(const Rational& rhs)       // *this = rhs;
{

    setNumerator(rhs.getNumerator());
	setDenominator(rhs.getDenominator());


	return *this;

}

Rational  Rational::operator+(const Rational& addend) const// returns *this + addend
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

Rational  Rational::operator-() const                     // returns -(*this)
{

    return Rational(getNumerator() * -1, getDenominator());

}

Rational  Rational::operator-(const Rational& subtrahend) const// returns *this - subtrahend
{
    //return add(subtrahend.additiveInverse());
    //return operator+ (subtrahend.operator-()); //not a pretty princes
    return *this + -subtrahend;
}

Rational  Rational::operator*(const Rational& multiplicand) const// returns *this * multiplicand
{
    Rational multi;

	multi.data.first = getNumerator() * multiplicand.data.first;
	multi.data.second = getDenominator() * multiplicand.data.second;
	multi.reduce();

	return multi;

}

Rational  Rational::operator/(const Rational& divisor) const// returns *this / divisor
{
    Rational divi;

	divi.data.first = getNumerator() * divisor.data.second;
	divi.data.second = getDenominator() * divisor.data.first;
	divi.reduce();

	return divi;
}

bool Rational::operator==(const Rational& rhs) const     // *this == rhs
{
    Rational rat1 = *this, rat2 = rhs;

    rat1.reduce();
    rat2.reduce();

    return rat1.getNumerator() == rat2.getNumerator() && rat1.getDenominator() == rat2.getDenominator();

}

bool Rational::operator!=(const Rational& rhs) const     // *this != rhs
{
    return !(*this == rhs);

}

bool Rational::operator< (const Rational& rhs) const     // *this <  rhs
{
    Rational rat1 = *this, rat2 = rhs;
	
	int myLCM = lcm(rat1.getDenominator(), rat2.getDenominator());
	int opOne = myLCM / rat1.getDenominator() * rat1.getNumerator();
	int opTwo = myLCM / rat2.getDenominator() * rat2.getNumerator();
	
	return opOne < opTwo;

}

bool Rational::operator<=(const Rational& rhs) const     // *this <= rhs
{
    return (*this < rhs || *this == rhs);
    
}

bool Rational::operator> (const Rational& rhs) const     // *this >  rhs
{
    return !(*this <= rhs);

}

bool Rational::operator>=(const Rational& rhs) const     // *this >= rhs
{
    return !(*this < rhs);

}

