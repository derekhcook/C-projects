// Derek Cook
// Cs 2336
// lab 47

#include <lab47.h>

BigInt  BigInt::operator* ( char digit ) const
{
    BigInt product;
    if(digit == '0')
        return BigInt();

    if(this->sign == ZERO)
        return *this;

    product.sign = this->sign;

    BigInt temp(*this);

    for(int a = 0; a < (digit - '0'); a++)
    {
        product = product + temp;
    }
    return product;
}

BigInt  BigInt::operator* ( const BigInt& rhs ) const
{
    BigInt product, copy(rhs);

    uint size = rhs.digits.size();

    for(uint i = 0; i < size; i++)
    {
        BigInt temp;
        temp = *this * copy.digits.front();
        copy.digits.pop_front();

        for(uint j = 0; i > j; j++)
            temp.digits.push_front('0');

        product = product + temp;
    }
    if((this->sign == NEGATIVE) && (rhs.sign == NEGATIVE))
        product.sign = POSITIVE;
    else if((this->sign == ZERO) || (rhs.sign == ZERO))
        product.sign = ZERO;
    else if((this->sign == NEGATIVE) || (rhs.sign == NEGATIVE))
        product.sign = NEGATIVE;
    else
        product.sign = POSITIVE;
    return product;
}