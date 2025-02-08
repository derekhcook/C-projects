// Derek Cook
// CS 2336
// Lab 26

#include<vector>
#include<math.h>

using namespace std;

int meanUsingIndexing(const vector<int>& v)
{
    vector<int>::size_type i, n = v.size();
    double sum = 0;

    for(i = 0; i < n; ++i)
    {
        sum += v[i];
    }
    sum = round(sum/n);

    return sum;
}

int meanUsingIterators(const vector<int>& v)
{
    vector<int>::const_iterator itr, n = v.cend();
    double sum = 0;

    for (itr = v.cbegin(); itr < n; ++itr)
    {
        sum += *itr;
    }

    sum = round(sum/v.size());
    return sum;
}

int meanUsingPointers(const vector<int>& v)
{
    vector<int>::const_pointer ptr, n = v.data() + v.size();
    double sum = 0;

    for (ptr = v.data(); ptr < n; ++ptr)
    {
        sum += *ptr;
    }
    sum = round(sum/v.size());
    return sum;
}