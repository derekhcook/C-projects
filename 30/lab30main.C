#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <IntegerSet.h>

using namespace std;

void sieveOfEratosthenes(IntegerSet& prime);

int main()
{
  int n;
   
  cin >> n;
   
  // Create an empty Integerset that can represent the range 0,1,...,n
  IntegerSet prime(n+1);

  for (uint i = 2; i < prime.size(); i++)
    prime.set(i);

  auto start = chrono::system_clock::now();
  sieveOfEratosthenes(prime);
  cout << prime;
  auto stop = chrono::system_clock::now();
  cerr << chrono::duration_cast<chrono::milliseconds>(stop-start).count()
       << "ms" << endl;
   
  return EXIT_SUCCESS;
}
