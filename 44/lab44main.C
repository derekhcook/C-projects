#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>

using namespace std;

bool isPalindrome(string);
void rmPuncSpaces(string&);

int main()
{
  string str;

  while (getline(cin, str))
  {
    cout << str;
    rmPuncSpaces(str);
    cout << " is ";
    if (!isPalindrome(str))
      cout << "not ";
    cout << "a palindrome" << endl;
  }

  return EXIT_SUCCESS;
}

void rmPuncSpaces(string& str)
{
  int i;
  string wsPunct;                       // whitespace & punctuation
  string::size_type idx;

  for (i=0; i<128; ++i)
    if (isspace(i) || ispunct(i))
      wsPunct += i;

  while ((idx = str.find_first_of(wsPunct)) != string::npos)
    if (idx == 0)                       // it's at the beginning
      str = str.substr(idx+1);
    else if (idx == str.length() - 1)   // it's at the end
      str = str.substr(0,idx);
    else                                // it's interior
      str = str.substr(0, idx) + str.substr(idx+1);

}
