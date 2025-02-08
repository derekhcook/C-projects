// Derek Cook
// CS 2336
// Lab 27

#include <algorithm> // for sort

template<typename T>
pair<T, int> modeUsingIndexing(const vector<T>& v)
{
    vector<T> copy(v); // O(N)
    pair<T, int> myMode;
    typename vector<T>::size_type i, n = copy.size();
    sort(copy.begin(), copy.end()); // O(N log N)
    int count = 1;
    int countMode = 0;
    myMode.first = copy[0];
    myMode.second = 1;

    for (i = 0; i < n - 1; i++) // O(N)
    {
        if(copy[i] == copy[i + 1])//myMode.first
        {
            count++;
            if(count > countMode)
            {
                countMode = count;
                myMode.first = copy[i];
                myMode.second = countMode;
            }
        }
        else
        {
            count = 1;
        }
        

    }
    return myMode;
}

template<typename T>
pair<T, int> modeUsingIterators(const vector<T>& v)
{
    vector<T> copy(v); // O(N)
    pair<T, int> myMode;
    typename vector<T>::iterator itr = copy.begin(), n = copy.end();
    sort(copy.begin(), copy.end()); // O(N log N)
    int count = 1;
    int countMode = 0;
    myMode.first = *itr;
    myMode.second = 1;

    for (itr = copy.begin(); itr < n - 1; itr++) // O(N)
    {
        if(*itr == *(itr + 1))//myMode.first
        {
            count++;
            if(count > countMode)
            {
                countMode = count;
                myMode.first = *itr;
                myMode.second = countMode;
            }
        }
        else
        {
            count = 1;
        }
        

    }
    return myMode;
    
}

template<typename T>
pair<T, int> modeUsingPointers(const vector<T>& v)
{
    vector<T> copy(v); // O(N)
    pair<T, int> myMode;
    typename vector<T>::pointer ptr = copy.data(), n = copy.data() + copy.size();
    sort(copy.begin(), copy.end());
    int count = 1;
    int countMode = 0;
    myMode.first = *ptr;
    myMode.second = 1;

    for (ptr = copy.data(); ptr < n - 1; ptr++) // O(N)
    {
        if(*ptr == *(ptr + 1))//myMode.first
        {
            count++;
            if(count > countMode)
            {
                countMode = count;
                myMode.first = *ptr;
                myMode.second = countMode;
            }
        }
        else
        {
            count = 1;
        }
        

    }
    return myMode;
    
}
