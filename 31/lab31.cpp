// Derek Cook
// CS 2336
// Lab 31

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

const string ID = "Derek Cook - CS 2336 - Lab 31\n\n";

int main()
{
    string inputLine;
    vector<string> filenames;
    uint l = 0;

    // output ID line
    cout << ID;
    // read an unknmown # of file names from standard input, one
    // per line
    while (getline(cin, inputLine))
    {
        filenames.emplace_back(inputLine);
        if (l < inputLine.length())
        {
            l = inputLine.length();
        }
    }
    uint c = (60 - l) / (l + 2) + 1;
    uint r = filenames.size() / c;
    c = filenames.size() / r;
    sort(filenames.begin(), filenames.end());
    vector<string>::size_type i, j;
    cout << setfill('-') << setw(60) << '-' << setfill(' ') << endl;
    for (i = 0; i < r; ++i)
    {
        for (j = i; j < (r * c - (r - i)); j += r)
        {
            cout << left << setw(l + 2) << filenames[i];
        }
        cout << left << setw(l) << filenames[r * c - (r - i)] << endl;
    }
    
    return 0;
}