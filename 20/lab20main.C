#include <iostream>
#include <string>

using namespace std;

// function template prototypes
template<typename T>
void mySwap(T& first, T& second);
template<typename T>
void bubbleSort(T *array, int n);

#include "lab20.cpp"

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

int main()
{
  const int aCount = 5, bCount = 7, cCount = 5, dCount = 8;
  int a[aCount] = {5, 4, 3, 2, 1};
  double b[bCount] = {7.7, 6.6, 5.5, 4.4, 3.3, 2.2, 1.1};
  char c[cCount] = {'H', 'E', 'L', 'L', 'O'};
  string d[dCount] = {"Cadillac", "Oldsmobile", "Chevrolet",
                      "Toyota", "Lexus", "Dodge", "GMC", "BMW"};

  cout << "Array a contains:" << endl;
  printArray(a, aCount);      // integer print function template
  bubbleSort(a, aCount);      // integer sort function template
  printArray(a, aCount);      // integer print function template

  cout << "Array b contains:" << endl;
  printArray(b, bCount);      // double print function template
  bubbleSort(b, bCount);      // double sort function template
  printArray(b, bCount);      // double print function template

  cout << "Array c contains:" << endl;
  printArray(c, cCount);      // character print function template
  bubbleSort(c, cCount);      // character sort function template
  printArray(c, cCount);      // character print function template

  cout << "Array d contains:" << endl;
  printArray(d, dCount);      // string print function template
  bubbleSort(d, dCount);      // string sort function template
  printArray(d, dCount);      // string print function template

  return 0;
}
