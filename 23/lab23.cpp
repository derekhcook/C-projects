// Derek Cook
// CS 2336
// Lab 23

// function template prototype
template<typename T>
int numDistinct(const T *array, int n)
{
    int distinct;

    if(n == 0)
    {
        distinct = 0;
    }
    else
    {
        const T *value = array;
        bool result = true;

        distinct = numDistinct(array + 1, n - 1);

        for(int j = 1; j < n; j++)
        {
            if(array[j] == *value)
                result = false;
        }

        if(result == true)
            distinct++;

    }



    return count;
}