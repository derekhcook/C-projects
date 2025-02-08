// Derek Cook
// CS 2336
// Lab 25

// overloaded operator << as a friend
template<typename U>
/*friend*/ ostream& operator<<(ostream& output, const Accumulator<U>& obj)
{
    output << obj.getTotal();
    return output;
}
template<typename T>
Accumulator<T>::Accumulator(const T& value)    // constructor
{
    //initialize total to value
    total = value;
}

// access and update functions
template<typename T>
T Accumulator<T>::getTotal() const                   // return total
{
    return total;
}

template<typename T>
void Accumulator<T>::addValue(const T& value)        // add (+) value to total
{
    total = total + value;
    //add value to total
}
