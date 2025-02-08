// Derek Cook
// Cs 2336
// Lab 33

template <typename T>
void shellSort(vector<T>& v)
{
    //Both programs work, but mine is faster than the top one
    
    typename vector<T>::size_type i, j, l, k, n = v.size();
    for (k = 1; k <= n / 9; k = 3 * k + 1)
    {}

    while (k > 1)
    {
        //build sublist; sort sublist; put back
        for (i = 0; i < k; ++i)
        {
            vector<T> sublist;
            for (j = i + 1;j < n; j += k)
            {
                sublist.emplace_back(v[j]);
            }
            insertionSort(sublist);
            for (j = i, l = 0; j < n && l < sublist.size(); j += k, ++l)
            {
                v[j] = sublist[l];
            }
        }
        // update k
        k /= 3;
    }
    insertionSort(v);

    /*int n = v.size();
    for (int g = n/2; g > 0; g /= 2)
    {
        for (int i = g; i < n; i += 1)
        {
            int temp = v[i];

            int j;
            for (j = i; j >= g && v[j - g] > temp; j -= g)
            {
                v[j] = v[j - g];
            }
            v[j] = temp;
        }
    }*/  
}