#include <lab09.h>
#include <iostream>

using namespace std;

int main()
{
  Rational rat, temp;

  while (cin >> temp)
  {
    rat = temp;
    cout << "rat = " << rat;
    cout << " ++rat = " << ++rat << endl;

    rat = temp;
    cout << "rat = " << rat;
    cout << " rat++ = " << rat++;
    cout << " rat = " << rat << endl;

    rat = temp;
    cout << "rat = " << rat;
    cout << " --rat = " << --rat << endl;

    rat = temp;
    cout << "rat = " << rat;
    cout << " rat-- = " << rat--;
    cout << " rat = " << rat << endl;
  }

  return EXIT_SUCCESS;
}
