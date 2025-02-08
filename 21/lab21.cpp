// Derek Cook
// CS 2336
// Lab 21

// function template prototype
template<typename T>
const T *linearSearch(const T *array, int n, T itemToFind)
{
    if (n <= 0)
        return 0;
    if (*array == itemToFind)
    {
        return array;
    }
    else
    {
        return linearSearch(array + 1, n - 1, itemToFind);
    }
}
