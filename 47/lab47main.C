#include <lab47.h>

using namespace std;

BigInt factorial(BigInt n);

int main()
{
  BigInt a(2305), b(-11);
  char i;

  for (i = '0'; i <= '9'; ++i)
    cout << a << " * " << i << " = " << a * i << endl;

  cout << a << " * " << b << " = " << a * b << endl;

  while (cin >> a >> b)
  {
    cout << a << " * " << b << " = " << a * b << endl;
  }

  cout << endl << "Factorials" << endl;

  BigInt n(0);
  for ( ; n < BigInt(21); n = n + 1)
  {
    if (n < BigInt(10))
      cout << ' ';
    cout << n << "! = " << factorial(n) << endl;
  }

  return EXIT_SUCCESS;
}

BigInt factorial(BigInt n)
{
  if (n == BigInt(0))
    return BigInt(1);
  else
    return n * factorial(n - 1);
}
