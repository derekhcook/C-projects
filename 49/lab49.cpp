// Derek Cook
// Cs 2336
// Lab 49

#include <queue>
#include <vector>

template <typename T>
void pqSort(vector<T>& v)
{
	priority_queue<T> priqeu;
	
	uint size = v.size() - 1;
	
	for (uint i = 0; i <= size; ++i)
		priqeu.push(v[i]);
	while (!priqeu.empty())
	{
		v[size] = priqeu.top();
		priqeu.pop();
		--size;
	}
}