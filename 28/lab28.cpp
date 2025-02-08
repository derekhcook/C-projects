// Derek Cook
// CS 2336
// Lab 28

template<typename T>
vector<Frequency<T>> distribution(const vector<T>& v)
{
    vector<Frequency<T>> myDist;
    typename vector<Frequency<T>>::iterator itr;
    typename vector<T>::const_pointer ptr, end = v.data() + v.size();

    for (ptr = v.data(); ptr < end; ++ptr)
    {
        itr = find(myDist.begin(), myDist.end(), *ptr);
        if (itr == myDist.end()) // then we didnt fint the *ptr in myDist
        {
            myDist.emplace_back(Frequency<T>(*ptr));
        }
        else // we found *ptr in myDist; increment frequency
        {
            itr->increment();
        }
    }

    return myDist;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<Frequency<T>>& v)
{
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        out << v.at(i).getValue() << " -> " << v.at(i).getFrequency() << '\n';
    }
    return out; //returns value of v then frequency
}

template<typename T>
bool Frequency<T>::operator==(const T rhs) const
{
    return (*this).getValue() == rhs; //rhs = *ptr; use get value function to compare to rhs
}

template<typename T>
bool Frequency<T>::operator< (const Frequency<T> rhs) const
{
    return (*this).getFrequency() < rhs.getFrequency();//compare little f frequency
}
