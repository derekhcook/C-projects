// Derek Cook
// Cs 2336
// Lab 40

#include <stack>
#include <cctype>
#include <cstdlib>
#include <string>

using namespace std;

bool isNestedCorrectly(string s)
{
    stack<char> delim;

    for (uint i = 0; i < s.length(); ++i)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			delim.push(s[i]);
		}
	}
	for (uint i = 0; i < s.length(); ++i)
	{
		if (s[i] == ')' || s[i] == '}' || s[i] == ']')
		{
			delim.pop();
		}
	}
	for (uint i = 0; i < s.length(); ++i)
	{
		if (s[0] == ')')
		{
			return false;
		}
	}
	for (uint i = 0; i < s.length(); ++i)
	{
		if (delim.empty())
		{
			return true;
		}
	}
	return false;
}