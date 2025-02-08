#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>

using namespace std;

// isPalindrome is a recursive function that returns true if string s
// is a palindrome and false otherwise
bool isPalindrome(string s);

// rmPuncSpaces returns string s with all punctuation and whitespace
// characters removed
string rmPuncSpaces(string s);

int main()
{
  string str;

  while (getline(cin, str))
  {
    cout << str;
    str = rmPuncSpaces(str);
    cout << " is ";
    if (!isPalindrome(str))
      cout << "not ";
    cout << "a palindrome" << endl;
  }

  return EXIT_SUCCESS;
}

string rmPuncSpaces(string str)
{
  // base case for stopping recursion
  if (str.length() == 0)
    return str;

  // general case; if the first character of str is either whitespace
  // or punctuation, recurse with the first character (index 0) from
  // str removed
  else if (isspace(*(str.begin())) || ispunct(*(str.begin())))
    return rmPuncSpaces(str.substr(1));

  // general case continued; if the first character of str is neither
  // whitespace nor punctuation, return the concatenation of the first 
  // character and the value from recursing with the first character
  // (index 0) from str removed
  else
    return *(str.begin()) + rmPuncSpaces(str.substr(1));
}
