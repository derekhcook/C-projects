#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

template <typename T>
void pqSort(vector<T>& v);

#include <lab49.cpp>

const int N = 100000;
enum TEST_TYPE {RANDOM, ASCENDING, DESCENDING};

int main()
{
  vector<int> v, w, x;
  default_random_engine ran;
  uniform_int_distribution<> dis; // [0..2^31 - 1]
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
          v.push_back(dis(ran));
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
    pqSort(w);
    auto stop = chrono::system_clock::now();
    cout << "PQ Sort: "
         << chrono::duration_cast<chrono::milliseconds>(stop-start).count() 
         << "ms" << endl;

    if (x != w)
      cout << "Sort didn't work correctly" << endl;
    cout << endl;
  }
  return EXIT_SUCCESS;
}
