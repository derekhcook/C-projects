// Derek Cook
// Cs 2336
// Lab 32

template <typename T>
void exchangeSort(vector<T>& v)
{
    /*uint pass, sub;

    for(pass = 0; pass <= v.size() - 2; ++pass)
    {
        for(sub = pass + 1; sub < v.size(); ++sub)
        {
            if(v[pass] > v[sub])
            {
                swap(v[pass], v[sub]);
            }
        }
    }*/




    typename vector<T>::pointer pass, sub, n = v.data() + v.size();
    T temp;

    for(pass = v.data(); pass <= n - 2; ++pass)
    {
        for(sub = pass + 1; sub < n; ++sub)
        {
            if(*pass > *sub)
            {
                temp = *pass;
                *pass = *sub;
                *sub = temp;
            }
        }
    }
}