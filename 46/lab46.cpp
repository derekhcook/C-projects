// Derek Cook
// Cs 2336
// Lab 46

#include <lab46.h>

BigInt BigInt::operator+(const BigInt& rhs) const
{
	BigInt sum, quotient, subtrahend(rhs);
	int add, sub, convert1, convert2, carry = 0;
	
	if (this->sign == ZERO)
		return rhs;
	else if (rhs.sign == ZERO)
		return *this;
	else if (this->sign == rhs.sign) // either both POSITIVE or both NEGATIVE, so add
	{
		BigInt addend(rhs);
		//return *this + copy;
		//return *this + rhs;
		//return digits + rhs.digits;
		
		for (uint i = 0; i < digits.size(); ++i)
		{
			if (digits.size() > addend.digits.size())
			{
				addend.digits.push_back(ZERO);
			}
			
			convert1 = digits[i] - 0;
			convert2 = addend.digits[i] - 0;
			add = (carry + convert1 + convert2) % 10;
			sum.digits[i] = add;
			carry = add / 10;
		}
		
		return sum;
	}
	
	else // One is POSITIVE and one is NEGATIVE, so subtract
	{
		//return *this - copy;
		//return *this - rhs;
		//return digits - rhs.digits;
		//return copy->digits - subtrahend.digits;
		
		for (uint i = 0; i < digits.size(); ++i)
		{
			if (digits.size() > subtrahend.digits.size())
			{
				subtrahend.digits.push_back(ZERO);
			}
			
			convert1 = digits[i] - 0;
			convert2 = subtrahend.digits[i] - 0;
			sub = (carry + convert1 + convert2) % 10;
			quotient.digits[i] = sub;
			carry = sub / 10;
		}
		
		return quotient;
	}
}

BigInt BigInt::operator- ( const BigInt& rhs ) const
{
	BigInt subtrahend(rhs); // Use the copy constuctor
	
	if (rhs.sign == NEGATIVE)
		subtrahend.sign = POSITIVE;
	else if (rhs.sign == POSITIVE)
		subtrahend.sign = NEGATIVE;
	
	return *this + subtrahend;
}
