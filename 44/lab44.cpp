// Derek Cook
// Cs 2336
// Lab 44

#include <deque>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;


bool isPalindrome(string s)
{
	deque<char> platosPhylisophicalThoughts;
	
	transform (s.cbegin(), s.cend(), s.begin(), [](unsigned char c) { return toupper(c); });

	for (uint i = 0; i < s.length(); ++i)
	{
		platosPhylisophicalThoughts.push_back(s[i]);
	}
	while(!platosPhylisophicalThoughts.empty())
	{
		if (platosPhylisophicalThoughts.front() == platosPhylisophicalThoughts.back())
		{
			platosPhylisophicalThoughts.pop_front();
			platosPhylisophicalThoughts.pop_back();
		}
		else
		{
			return false;
		}
		if(platosPhylisophicalThoughts.size() == 1)
		{
			platosPhylisophicalThoughts.pop_front();
			break;
        }
	}
	
	return true;

}
