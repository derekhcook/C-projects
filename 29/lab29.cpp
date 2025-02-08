// Derek Cook
// CS 2336
// Lab 29


//swap and reverse(begin() + (i + 1), end());
template<typename T>
bool nextPermutation(vector<T>& v)
{
    //scan in from right to left until left < right;-
    //then set i = left;-
    // compare elements from right to left to element in i;-
    // when you reach an element higher to the one in i set j = index of higher element;-
    // swap elements at i and j;-
    // swap second and last element;
    typename vector<T>::iterator itr = v.begin(), n = v.end();
    for(itr = n - 1; itr > v.begin(); itr--)
    {
        if(*itr > *(itr - 1))
        {
            for(typename vector<T>::iterator itr2 = n - 1; itr2 >= 0; itr--)
            {
                if(*(itr - 1) < *itr2)
                {
                    swap(*(itr - 1), *itr2);
                    swap(*itr, *(itr2 + 1));
                    return true;
                }
                //return false;
            }
             //i = v.at(x - 1);
             //j = v.at(x);
            //swap(*itr, *(itr - 1));
            //return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}
//bool nextPermutation(int);
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    int size = v.size();
    for(int i = 0; i < size; i++)
    {
        os << v.at(i) << '\n';
    }
    return os;
}