#include <iostream>
#include <cstdlib> // contains prototypes for functions srand and rand
#include <vector>
#include <cmath>

using namespace std;

ostream& operator<<(ostream& os, const vector<uint>& v);

void bucketSort(vector<uint>& v, uint numDigits);

int main()
{
  uint numDigits, n, shiftValue, scalingFactor, i;
  vector<uint> v;

  // randomize random number generator using current time
  srand(time(0));

  cout << "Enter the number of digits in each of the values to be sorted:"
       << endl;
  cin >> numDigits;

  cout << "Enter the number of values to be sorted:" << endl;
  cin >> n;

  shiftValue = uint(pow(10.0, int(numDigits - 1)));
  scalingFactor = uint(pow(10.0, int(numDigits))) - 1 - shiftValue;

  for (i = 0; i < n; ++i)
    v.push_back(shiftValue + rand() % scalingFactor);

  cout << v << endl;
  bucketSort(v, numDigits);

  return 0;
}

ostream& operator<<(ostream& os, const vector<uint>& v)
{
  vector<uint>::const_iterator itr;

  os << "vector" << endl << '{' << endl;
  for (itr = v.begin(); itr < v.end(); ++itr)
    os << "  [" << itr - v.begin() << "] = " << *itr << endl;
  os << '}' << endl;

  return os;
}
