// Derek Cook
// Cs 2336
// Lab 42

#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <cctype>

using namespace std;

bool isPalindrome(string s)
{
    stack<char> stack;
    queue<char> queue;

    transform (s.cbegin(), s.cend(), s.begin(), [](unsigned char c) { return toupper(c); });

    for(uint i = 0; i < s.length(); ++i)
    {
        stack.push(s[i]);
		queue.push(s[i]);
    }

    for (uint i = 0; i < stack.size() && i < queue.size(); ++i)
	{
		if (stack.top() != queue.front())
			return false;
		else
		{
			stack.pop();
			queue.pop();
		}
	}
	return true;
}