#include <cstdlib>
#include <iomanip>
#include <string>
#include <algorithm>
#include <lab29.h>

using namespace std;

template<typename T>
void generatePermutations(const vector<T>& v, ostream& out);

int main()
{
  vector<int> a;
  a.push_back(2);
  a.push_back(3);
  a.push_back(0);
  a.push_back(5);
  generatePermutations(a, cout);

  vector<double> b;
  b.push_back(2.3);
  b.push_back(0.5);
  cout << fixed << setprecision(1) << showpoint;
  generatePermutations(b, cout);

  string inputLine;
  vector<char> perm;

  while(getline(cin, inputLine))
  {
    perm.clear();
    perm.insert(perm.begin(), inputLine.begin(), inputLine.end());
    generatePermutations(perm, cout);
  }

  return EXIT_SUCCESS;
}

template<typename T>
void generatePermutations(const vector<T>& v, ostream& out)
{
  vector<T> perm(v), copy;
  sort(perm.begin(), perm.end());
  copy = perm;

  out << perm << endl;
  while (nextPermutation(perm))
    out << perm << endl;
  out << endl;
  
  if (perm != copy)
    out << "Gotcha; this shouldn't print" << endl;
}
