#include <iostream>
#include <stack>
using namespace std;
bool isSymbol(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return true;
    else
        return false;
}
int prec(char symbol)
{
    if (symbol == '+' || symbol == '-')
        return 1;
    else if (symbol == '*' || symbol == '/')
        return 2;
    else if (symbol == '^')
        return 3;
    else
        return 0;
}
int main()
{
    stack<char> exp;
    exp.push('#');
    string infix = "A ^ B * C- D + E / F / G + H ";
    char *postfix = new char[infix.size()];
    int i = 0, j = 0;

    while (i < infix.size())
    {
        if (!isSymbol(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (prec(infix[i]) > prec(exp.top()))
                exp.push(infix[i++]);
            else
            {
                postfix[j++] = exp.top();
                exp.pop();
            }
        }
    }
    while (!exp.empty())
    {
        postfix[j++] = exp.top();
        exp.pop();
    }

    i = 0;
    while (i < infix.size())
    {
        cout << postfix[i++];
    }
    return 0;
}