// Derek Cook
// Cs 2336
// Lab 41

#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <cctype>
#include <cstring>

using namespace std;
bool hasPrecedenceGreaterThanOrEqualTo(char, char);

// Function infix2Postfix accepts an infix expression and converts to the
// equivalent postfix expression. The postfix expression is written to
// ostream out.
void infix2Postfix(string infix, ostream& out)
{
    stack<char> symbols;
    int i = 0;
    int infixLength = infix.length();

    for (i = 0; i < infixLength; i++)
    {
        if(isspace(infix[i]))
        {
            continue;
        }
        else if(infix[i] == '(')
        {
            symbols.push('(');
        }
        else if(infix[i] >= 65 && infix[i] <= 90)
        {
            out << infix[i] << " ";
        }
        else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '*')
        {

            while(!symbols.empty() && (symbols.top() != '(') && hasPrecedenceGreaterThanOrEqualTo(symbols.top(), infix[i]))
            {
                out << symbols.top() << " ";
                symbols.pop();
            }
            symbols.push(infix[i]);
        }
        else
        {
            while(!symbols.empty() && symbols.top() != '(')
            {
                out << symbols.top() << " ";
                symbols.pop();
            }
            if(!symbols.empty())
            {
                if(symbols.top() == '(')
                    symbols.pop();
            }
            else
            {
                out << "error";
                break;
            }
        }
    }
    while(!symbols.empty())
    {
        if(symbols.top() == '(')
        {
            out << "error";
            break;
        }
        out << symbols.top() << " ";
        symbols.pop();
    }
}

// Function hasPrecedenceGreaterThanOrEqualTo accepts two character
// parameters, each representing an arithmetic operator (+, -, *, /).
// The function returns true if operator1 has precedence greater than 
// or equal to operator2 and false otherwise.
bool hasPrecedenceGreaterThanOrEqualTo(char operator1, char operator2)
{
    int op1, op2;
	
	if(operator1 == '+' || operator1 == '-')
    {
		op1 = 1;
    }
	if(operator1 == '*' || operator1 == '/')
    {
		op1 = 2;
    }
	if(operator2 == '+' || operator2 == '-')
    {
		op2 = 1;
    }
	if(operator2 == '*' || operator2 == '/')
    {
		op2 = 2;
    }
	return op1 >= op2;
}
