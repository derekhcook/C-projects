#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <string>

using namespace std;

template<typename T>
pair<T, int> modeUsingIndexing(const vector<T>& v);

template<typename T>
pair<T, int> modeUsingIterators(const vector<T>& v);

template<typename T>
pair<T, int> modeUsingPointers(const vector<T>& v);

#include "lab27.cpp"

template<typename T>
void callModeFunctions(const vector<T>& v, string nameOfVector)
{
  if (v.size() == 0)
    cout << "No data\n";    
  else
  {
    cout << "For vector " << nameOfVector << ":" << endl;
    pair<T, int> result = modeUsingIndexing(v);
    cout << " Using Indexing Mode = " << result.first
         << " # of occurrences = " << result.second << endl;

    result = modeUsingIterators(v);
    cout << "Using Iterators Mode = " << result.first
         << " # of occurrences = " << result.second << endl;

    result = modeUsingPointers(v);
    cout << " Using Pointers Mode = " << result.first
         << " # of occurrences = " << result.second << endl;
    cout << endl;
  }
}

int main()
{
  const int aCount = 5, bCount = 1, cCount = 14, dCount = 12;
  int a[aCount] = {5, 5, 5, 5, 5};
  double b[bCount] = {7.7};
  char c[cCount] = {'r', 'a', 'c', 'e', 'c', 'a', 'r',
                    ' ', 'd', 'r', 'i', 'v', 'e', 'r'};
  string d[dCount] = {"Cadillac", "GMC", "GMC",
                      "Lexus", "Lexus", "Dodge", "GMC", "BMW",
                      "BMW", "GMC", "Dodge", "Lexus"};

  vector<int> aVector(a, a + sizeof(a) / sizeof(a[0]));
  callModeFunctions(aVector, "aVector");

  vector<double> bVector(b, b + sizeof(b) / sizeof(b[0]));
  callModeFunctions(bVector, "bVector");

  vector<char> cVector(c, c + sizeof(c) / sizeof(c[0]));
  callModeFunctions(cVector, "cVector");

  vector<string> dVector(d, d + sizeof(d) / sizeof(d[0]));
  callModeFunctions(dVector, "dVector");

  int num;
  vector<int> v;

  while (cin >> num)
    v.push_back(num);

  callModeFunctions(v, "v");

  return EXIT_SUCCESS;
}
