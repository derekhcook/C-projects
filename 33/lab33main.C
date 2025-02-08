#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <d_random.h>

using namespace std;

template <typename T>
void insertionSort(vector<T>& v)
{
  T *i, *j, *n = v.data() + v.size(), *start = v.data();
  T target;

  for (i = v.data() + 1; i < n; i++)
  {
    j = i;
    target = *i;
    while (j > start && target < *(j-1))
    {
      // shift elements up list to make room for insertion
      *j = *(j-1);
      j--;
    }
    // the location is found; insert target
    *j = target;
  }
}

template <typename T>
void shellSort(vector<T>& v);

#include <lab33.cpp>

const int N = 25000;
enum TEST_TYPE {RANDOM, ASCENDING, DESCENDING};

int main()
{
  vector<int> v, w, x;
  randomNumber rnd;
  TEST_TYPE testType;
  int i;

  for (testType = RANDOM;
       testType <= DESCENDING;
       testType = static_cast<TEST_TYPE>(testType + 1))
  {
    if (!v.empty())
      v.clear();
    switch (testType)
    {
      case RANDOM:
        for (i = 0; i < N; ++i)
          v.push_back(rnd.random(1000000));
        cout << "Random Data:" << endl;
        break;
      case ASCENDING:
        for (i = 0; i < N; ++i)
          v.push_back(i);
        cout << "Ascending Data:" << endl;
        break;
      case DESCENDING:
        for (i = 0; i < N; ++i)
          v.push_back(N - i);
        cout << "Descending Data:" << endl;
        break;
    }
    x = v;
    sort(x.begin(), x.end());

    w = v;
    auto start = chrono::system_clock::now();
    shellSort(w);
    auto stop = chrono::system_clock::now();
    cout << "Shell Sort: "
         << chrono::duration_cast<chrono::milliseconds>(stop-start).count() 
         << "ms" << endl;
    if (x != w)
      cout << "Sort didn't work correctly" << endl;
    cout << endl;
  }
  return EXIT_SUCCESS;
}
