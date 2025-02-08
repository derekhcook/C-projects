#include <iostream>
#include <string>

using namespace std;

// function template prototype
template<typename T>
int numDistinct(const T *array, int n);

#include "lab23.cpp"

template<typename T>
void printArray(const T *array, int count)
{
  if (count > 0)
  {
    cout << *array << " ";
    printArray(array + 1, count - 1);
  }
  else
    cout << endl;
}

template<typename T>
void printAndCountDistinct(const T *array, int n, string nameOfArray)
{
  int distinct;

  cout << "Array " << nameOfArray << " contains:" << endl;
  printArray(array, n);
  distinct = numDistinct(array, n);
  cout << "and has " << distinct << " distinct element"
       << (distinct > 1 ? "s." : ".") << endl << endl;
}

int main()
{
  const int aCount = 5, bCount = 7, cCount = 7, dCount = 12;
  int a[aCount] = {5, 5, 5, 5, 5};
  double b[bCount] = {7.7, 6.6, 5.5, 4.4, 3.3, 2.2, 1.1};
  char c[cCount] = {'r', 'a', 'c', 'e', 'c', 'a', 'r'};
  string d[dCount] = {"Cadillac", "Oldsmobile", "Chevrolet",
                      "Toyota", "Lexus", "Dodge", "GMC", "BMW",
                      "BMW", "GMC", "Dodge", "Lexus"};

  printAndCountDistinct(a, aCount, "a");
  printAndCountDistinct(b, bCount, "b");
  printAndCountDistinct(c, cCount, "c");
  printAndCountDistinct(d, dCount, "d");

  return 0;
}
