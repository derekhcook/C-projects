#include <iostream>
#include <string>

using namespace std;

// function template prototype
template<typename T>
const T *linearSearch(const T *array, int n, T itemToFind);

#include "lab21.cpp"

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
void printAndSearch(const T *array, int n, T itemToFind, string nameOfArray)
{
  const T *ptr;

  cout << "Array " << nameOfArray << " contains:" << endl;
  printArray(array, n);
  ptr = linearSearch(array, n, itemToFind);
  cout << itemToFind;
  if (ptr)
    cout << " is in array " << nameOfArray << " and is located at index "
         << ptr - array << endl << endl;
  else
    cout << " is not in array " << nameOfArray << endl << endl;
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

  printAndSearch(a, aCount, 5, "a");
  printAndSearch(a, aCount, 2, "a");
  printAndSearch(b, bCount, 1.1, "b");
  printAndSearch(b, bCount, 11.11, "b");
  printAndSearch(c, cCount, 'e', "c");
  printAndSearch(c, cCount, 'E', "c");
  printAndSearch(d, dCount, static_cast<string>("Lexus"), "d");
  printAndSearch(d, dCount, static_cast<string>("Mercedes"), "d");

  return 0;
}
