// Derek Cook
// Cs 2336
// Lab 34

template <typename T>
void miniVector<T>::insert(int i, const T& item)
// insert item at index i in the vector.
// Precondition vector is not empty and 0 <= i <= vSize.
// Postcondition the vector size increases by 1.
{
    if(empty() && i != 0)
    {
        throw underflowError("miniVector insert(): vector empty");
    }
    if(i < 0 or i > vSize)
    {
        throw indexRangeError("miniVector insert(): index range error", i, vSize);
    }
    push_back(item);
    
    for(int j = vSize - 1; j > i; --j)
    {
        swap(vArr[j], vArr[j - 1]);
    }
}
template <typename T>
void miniVector<T>::erase(int i)
// erase the item at index i in the vector.
// precondition vector is not empty and 0 <= i < vSize.
// Postcondition the vector size decreases by 1.
{
    if(empty() && i >= 0)
    {
        throw underflowError("miniVector erase(): vector empty");
    }
    if(i < 0 || i >= vSize)
    {
        throw indexRangeError("miniVector erase(): index range error", i, vSize);
    }
    int k;
    for(k = i; k < vSize - 1; ++k)
    {
        vArr[k] = vArr[k + 1];
    }
    
    pop_back();
}