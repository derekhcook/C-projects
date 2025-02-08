// Derek Cook
// Cs 2336
// Lab 39

#include <stack>
#include <algorithm>
#include <string>
#include <iostream>
#include <cctype>
#include <cstdlib>

using namespace std;

bool isPalindrome(string s)
{
    stack<char> a, b, c;
    int n = s.length();
    int j = 0;
    
    transform(s.cbegin(), s.cend(),
              s.begin(), // write to the same location
              [](unsigned char c) { return toupper(c);});

    for(int i = 0; i < n; ++i)
    {
        a.push(s[i]);
        b.push(s[i]);
    }
    int m = a.size();
    while(j < m)
    {
        c.push(b.top());
        b.pop();
        j++;
    }
    for (int i = 0; i < m; ++i)
    {
        if (a.top() != c.top())
        {
            return false;
        }
    }
    return true;
}
/*  1)  add the chars from s to both a & b (backwards order)
    2)  sacrifice b to initialize c. Push the top of b to c
        and then pop b. Continue until b is empty.
    3)  Now b is empty. a contains s backwards and c contains
        s forward.
    4)  if a == c, then return true; otherwise, return false.
*/