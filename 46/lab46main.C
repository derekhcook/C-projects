#include <lab46.h>

using namespace std;

int main()
{
  BigInt a, b;

  while (cin >> a >> b)
  {
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << b << " - " << a << " = " << b - a << endl;
  }

  cout << endl;
  cout << "Fibonacci Sequence" << endl;
  BigInt i(1), end(51), first(1), second(1);

  while (i < end)
  {
    cout << "Fib(" << i << ") = " << first << endl;
    second = first + second;
    first = second - first;
    i = i + 1;
  } 

  return EXIT_SUCCESS;
}
