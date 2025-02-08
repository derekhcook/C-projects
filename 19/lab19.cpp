// Derek Cook
// CS 2336
// Lab 19

#include <bits.h>
#include <climits>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

// isPalindrome is a recursive function that returns true if string s
// is a palindrome and false otherwise
bool isPalindrome(string s)
{
    for (uint i = 0; i < s.length(); i++)
      {
          s[i] = tolower(s[i]);
      }
    if(s.length() == 0 || s.length() == 1)
    {
        return true;
    }
    else
    {
        if(s[0] == s[s.length()-1])
        {
            return isPalindrome(s.substr(1, s.length()-2));
        }
        else
        {
            return false;
        }
    }
}