// Derek Cook
// CS 2336
// Lab 20

// function template prototypes

template<typename T>
void mySwap(T& first, T& second)
{
    T temp;

    temp = first;
    first = second;
    second = temp;
}
template<typename T>
void bubbleSort(T *array, int n)
{
    int j;
 
    if (n <= 1)
    {
        return;
    }
    else
    {
        for (j = 0; j < n - 1; ++j)
        {
            if (array[j] > array[j + 1])
            {
                mySwap(array[j], array[j + 1]);
            }
        }
    }

    bubbleSort(array, n - 1);

}
