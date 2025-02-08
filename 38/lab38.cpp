// Derek Cook
// Cs 2336
// Lab 38

/*for (i = 0; i < K(numDigits;); ++i)
{
    1) distribution paass (one loop)
    2)gathering pass (two nested loops)
    3)cout >> v;
}*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

ostream& operator<<(ostream& os, const vector<uint>& v);

void bucketSort(vector<uint>& v, uint numDigits)
{   
    vector<vector<uint>> buckets(10);
    int vSize = v.size();
    for (uint i = 0, mod = 10; i < numDigits; ++i, mod *= 10)
    {
        for (int j = 0; j < vSize; ++j)
        {
            int num = v[j] % mod;
            while (num > 10)
            {
                num = num / 10;
            }
            buckets[num].emplace_back(v[j]);
        }

        v.clear();
        for (int r = 0; r < 10; ++r)
        {
            int bSize = buckets[r].size();
            for (int c = 0; c < bSize; ++c)
            {
                v.emplace_back(buckets[r][c]);
            }
            buckets[r].clear();
        }
        
        cout << v << endl;
    }
}