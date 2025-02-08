// Derek Cook
// Cs 2336
// Lab 45

#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <cmath>
#include <queue>
#include <lab45.h>

using namespace std;

BigInt::BigInt()                                      
{
	sign = ZERO;
	digits.emplace_back('0');
}

BigInt::BigInt( int num )                             
	: BigInt(to_string(num))
	{
	}

BigInt::BigInt( const string str )                    
{
	if (isInt(str))
	{
		string::const_reverse_iterator ritr, end = str.crend();
		
		sign = POSITIVE;
		
		for (ritr = str.crbegin(); ritr < end; ++ritr)
		{
			if (isspace(*ritr))
				continue;
			else if (isdigit(*ritr))
				digits.emplace_back(*ritr);
			else if (*ritr == '-')
				sign = NEGATIVE;				
		}
		
		while (!digits.empty() && digits.back() == '0')
			digits.pop_back();
		
		if (digits.empty())
		{
			sign = ZERO;
			digits.emplace_back('0');
		}
	}
	else
	{
		sign = ZERO;
		digits.emplace_back('0');
	}
}

BigInt::BigInt( const BigInt& other )                 
{
	sign = other.sign;
	digits = other.digits;
}

bool BigInt::operator==( const BigInt& rhs ) const
{
	return sign == rhs.sign && digits == rhs.digits;
}

bool BigInt::operator<( const BigInt& rhs ) const
{
	if(sign == ZERO && rhs.sign == ZERO)
	{
		return false;
	}
	else if(sign == ZERO && rhs.sign == POSITIVE)
	{
		return true;
	}
	else if(sign == ZERO && rhs.sign == NEGATIVE)
	{
		return false;
	}
	else if(sign == NEGATIVE && rhs.sign == ZERO)
	{
		return true;
	}
	else if(sign == NEGATIVE && rhs.sign == POSITIVE)
	{
		return true;
	}
	else if(sign == NEGATIVE && rhs.sign == NEGATIVE)
	{
		if(digits.size() > rhs.digits.size())
		{
			return true;
		}
		else if(digits.size() == rhs.digits.size())
		{
			for(uint i = digits.size()-1; i >= 0; --i)
			{
				if(digits[i] > rhs.digits[i])
				{
					return true;
				}
				if(digits[i] < rhs.digits[i])
				{
					return false;
				}
			}
			return false;
		}
		else
		{
			return false;
		}
	}
	else if(sign == POSITIVE && rhs.sign == NEGATIVE)
	{
		return false;
	}
	else if(sign == POSITIVE && rhs.sign == ZERO)
	{
		return false;
	}
	else if(sign == POSITIVE && rhs.sign == POSITIVE)
	{
		if(digits.size() < rhs.digits.size())
		{
			return true;
		}
		else if(digits.size() == rhs.digits.size())
		{
			for(uint i = digits.size()-1; i >= 1; --i)
			{
				if(digits[i] > rhs.digits[i])
				{
					return false;
				}
				if(digits[i] < rhs.digits[i])
				{
					return true;
				}
			}
			if(digits[0] > rhs.digits[0])
			{
				return false;
			}
			if(digits[0] < rhs.digits[0])
			{
				return true;
			}
			return false;
		}
		else
		{
			return false;
		}
	}
	return true;
}
