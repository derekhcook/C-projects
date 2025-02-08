#include <iostream>
#include <string>

using namespace std;

// function template prototype
template<typename T>
const T *binarySearch(const T *first, const T *last, T itemToFind);

#include "lab22.cpp"

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
  ptr = binarySearch(array, array + (n - 1), itemToFind);
  cout << itemToFind;
  if (ptr)
    cout << " is in array " << nameOfArray << " and is located at index "
         << ptr - array << endl << endl;
  else
    cout << " is not in array " << nameOfArray << endl << endl;
}

int main()
{
  const int aCount = 5, bCount = 7, cCount = 26, dCount = 10;
  int a[aCount] = {5, 15, 25, 35, 45};
  double b[bCount] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
  char c[cCount] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                    'u', 'v', 'w', 'x', 'y', 'z'};
  string d[dCount] = {"Audi", "BMW", "Bentley", "Buick", "Cadillac",
                      "Chevrolet", "Dodge", "GMC", "Jaguar", "Lexus"};

  printAndSearch(a, aCount, 25, "a");
  printAndSearch(a, aCount, 55, "a");
  printAndSearch(b, bCount, 1.1, "b");
  printAndSearch(b, bCount, 11.11, "b");
  printAndSearch(c, cCount, 'z', "c");
  printAndSearch(c, cCount, 'Z', "c");
  printAndSearch(d, dCount, static_cast<string>("Cadillac"), "d");
  printAndSearch(d, dCount, static_cast<string>("Mercedes"), "d");

  return 0;
}
