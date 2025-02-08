#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

bool isNestedCorrectly(string);

int main()
{
  string str;

  while (getline(cin, str))
  {
    cout << str;
    cout << " is nested ";
    if (!isNestedCorrectly(str))
      cout << "in";
    cout << "correctly" << endl;
  }

  return EXIT_SUCCESS;
}
