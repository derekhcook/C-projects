#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Function infix2Postfix accepts an infix expression and converts to the
// equivalent postfix expression. The postfix expression is written to
// ostream out.
void infix2Postfix(string infix, ostream& out);

// Function hasPrecedenceGreaterThanOrEqualTo accepts two character
// parameters, each representing an arithmetic operator (+, -, *, /).
// The function returns true if operator1 has precedence greater than 
// or equal to operator2 and false otherwise.
bool hasPrecedenceGreaterThanOrEqualTo(char operator1, char operator2);

int main()
{
  string infix;

  while (getline(cin, infix))
  {
    cout << "Infix:   " << infix << endl;
    cout << "Postfix: ";
    infix2Postfix(infix, cout);
    cout << endl;
  }

  return EXIT_SUCCESS;
}
