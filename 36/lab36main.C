#include <iostream>
#include <lab36.h>

using namespace std;

int main()
{
  Spiral spiral;
  uint n;           // the number of columns & rows

  cin >> n;

  spiral.initialize(n);
  spiral.build();
  cout << spiral;

  return EXIT_SUCCESS;
}
