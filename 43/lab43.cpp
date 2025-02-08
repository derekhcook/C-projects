// Derek Cook
// Cs 2336
// Lab 43

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

ostream& operator<<(ostream& os, const vector<uint>& v);

void bucketSort(vector<uint>& v, uint numDigits)
{
	vector<queue<uint>> buckets(10);
	
	int d = 1, m = 10;
	
	for (uint i = 0; i < numDigits; ++i)
	{
		for (uint j = 0; j < v.size(); ++j)
		{
			buckets[(v[j] % m) / d].push(v[j]);
		}
		m = m * 10;
		d = d * 10;

		uint x = 0;
		for (uint k = 0; k < v.size(); ++k)
		{
			uint c = 0;	
			while (c < buckets[k].size())
			{
				v[x] = buckets[k].front();
				buckets[k].pop();
				++x;
			}
		}
		
		cout << v;
	}
}