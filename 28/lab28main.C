#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <lab28.h>

using namespace std;

string ltrim(string s);
string rtrim(string s);

template<typename T>
vector<Frequency<T>> distribution(const vector<T>& v);

template<typename T>
ostream& operator<<(ostream& out, const vector<Frequency<T>>& v);

#include "lab28.cpp"

int main(int argc, char **argv)
{
  const int aCount = 5, bCount = 7, cCount = 7, dCount = 12;
  int a[aCount] = {5, 5, 5, 5, 5};
  double b[bCount] = {7.7, 6.6, 5.5, 4.4, 3.3, 2.2, 1.1};
  char c[cCount] = {'r', 'a', 'c', 'e', 'c', 'a', 'r'};
  string d[dCount] = {"Cadillac", "GMC", "GMC",
                      "Lexus", "Lexus", "Dodge", "GMC", "BMW",
                      "BMW", "GMC", "Dodge", "Lexus"};
  ifstream fin;

  if (argc != 2)
  {
    cerr << "Usage: " << *argv << " InputFileName" << endl;
    exit(EXIT_FAILURE);
  }

  fin.open(*(argv+1));
  if (fin.fail())
  {
    cerr << "Couldn't open input file: " << *(argv+1) << endl;
    exit(EXIT_FAILURE);
  }

  vector<int> aVector(a, a + sizeof(a) / sizeof(a[0]));
  cout << distribution(aVector) << endl;

  vector<double> bVector(b, b + sizeof(b) / sizeof(b[0]));
  cout << distribution(bVector) << endl;

  vector<char> cVector(c, c + sizeof(c) / sizeof(c[0]));
  cout << distribution(cVector) << endl;

  vector<string> dVector(d, d + sizeof(d) / sizeof(d[0]));
  vector<Frequency<string>> dVectorDist;
  dVectorDist = distribution(dVector);
  cout << "Before Sorting by Frequency" << endl << dVectorDist << endl;
  sort(dVectorDist.begin(), dVectorDist.end());
  cout << "After Sorting by Frequency" << endl << dVectorDist << endl;

  vector<char> charVec;
  vector<Frequency<char>> charVecDist;
  char ch;

  while (fin.get(ch))         // read the data char-by-char
    charVec.push_back(ch);

  charVecDist = distribution(charVec);
  cout << "Before Sorting by Frequency" << endl << charVecDist << endl;
  sort(charVecDist.begin(), charVecDist.end());
  cout << "After Sorting by Frequency" << endl << charVecDist << endl;

  fin.clear();                // forget we hit end-of-file earlier
  fin.seekg(0, ios::beg);     // move to the beginning of the file

  vector<string> wordVec;
  vector<Frequency<string>> wordVecDist;
  string word;

  while (fin >> word)         // read the data word-by-word
  { 
    word = ltrim(word);
    word = rtrim(word);
    if (word.length() > 0)
      wordVec.push_back(word);
  }

  wordVecDist = distribution(wordVec);
  cout << "Before Sorting by Frequency" << endl << wordVecDist << endl;
  sort(wordVecDist.begin(), wordVecDist.end());
  cout << "After Sorting by Frequency" << endl << wordVecDist << endl;

  return EXIT_SUCCESS;
}

// Function ltrim removes whitespace and punctuation from the beginning
// of string s
string ltrim(string s)
{
  if (s.length() == 0)
    return s;
  else if (isspace(*(s.begin())) || ispunct(*(s.begin())))
    return ltrim(s.substr(1));
  else
    return s;
}

// Function rtrim removes whitespace and punctuation from the end
// of string s
string rtrim(string s)
{
  if (s.length() == 0)
    return s;
  else if (isspace(*(s.end() - 1)) || ispunct(*(s.end() - 1)))
    return rtrim(s.substr(0, s.length() - 1));
  else
    return s;
}
