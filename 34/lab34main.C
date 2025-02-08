#include <iostream>
#include <cstdlib>
#include <d_vector.h>
#include <lab34.cpp>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const miniVector<T>& v)
{
  int i = 0;

  if (!v.empty())
  {
    os << "miniVector" << endl << '{' << endl;
    for (i = 0; i < v.size(); ++i)
      os << "  [" << i << "] = " << v[i] << endl;
    os << '}' << endl;
  }

  return os;
}

int main()
{
  int i, n;
  miniVector<int> v;

  cout << "v.size() = " << v.size() << endl;
  cout << "v.capacity() = " << v.capacity() << endl;

  // On an empty vector, check to see if erase throws
  // an underflowError exception
  try
  {
    v.erase(0);
  }
  catch (underflowError error)
  {
    cerr << "**1**" << error.what() << endl;
  }

  // On an empty vector, check to see if insert throws
  // an underflowError exception when pos is non-zero
  try
  {
    v.insert(1, 2002);
  }
  catch (underflowError error)
  {
    cerr << "**2**" << error.what() << endl;
  }

  // Insert into an empty vector at position 0
  try
  {
    v.insert(0, 2002);
  }
  catch (underflowError error)
  {
    cerr << "**3**" << error.what() << endl;
  }
  catch (indexRangeError error)
  {
    cerr << "**4**" << error.what() << endl;
  }
  cout << v << endl;

  // Attempt an insert at an invalid position
  try
  {
    v.insert(v.size() + 1, 2003);
  }
  catch (indexRangeError error)
  {
    cerr << "**5**" << error.what() << endl;
  }

  for (i = 0; i < 5; ++i)
    v.push_back(2305);
  cout << v << endl;

  try
  {
    n = v.size();
    for (i = 0; i < 2*n; i += 2)
      v.insert(i, i);
  }
  catch (indexRangeError error)
  {
    cerr << "**6**" << error.what() << endl;
  }
  cout << v << endl;

  // On a non-empty vector, check to see if erase throws
  // an indexRangeError exception
  try
  {
    v.erase(v.size());
  }
  catch (indexRangeError error)
  {
    cerr << "**7**" << error.what() << endl;
  }

  // On a non-empty vector, check to see if insert throws
  // an indexRangeError exception
  try
  {
    v.insert(v.size() + 1, 2002);
  }
  catch (indexRangeError error)
  {
    cerr << "**8**" << error.what() << endl;
  }

  try
  {
    while (v.size() > 0)
    {
      v.erase(0);
      cout << v << endl;
    }
  }
  catch (indexRangeError error)
  {
    cerr << "**9**" << error.what() << endl;
  }

  return EXIT_SUCCESS;
}
