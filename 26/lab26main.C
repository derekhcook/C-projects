#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int meanUsingIndexing(const vector<int>& v);
int meanUsingIterators(const vector<int>& v);
int meanUsingPointers(const vector<int>& v);

int main()
{
  int num;
  vector<int> v;

  while (cin >> num)
    v.push_back(num);

  if (v.size() == 0)
    cout << "No data\n";    
  else
  {
    cout << " Using Indexing Mean = " << meanUsingIndexing(v) << endl;
    cout << "Using Iterators Mean = " << meanUsingIterators(v) << endl;
    cout << " Using Pointers Mean = " << meanUsingPointers(v) << endl;
  }

  return EXIT_SUCCESS;
}
