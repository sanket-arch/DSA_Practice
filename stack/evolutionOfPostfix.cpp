
#include <bits/stdc++.h>
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
    else
        return 0;
}
// this  function is to convert infix to postfix
char *PostFix(string infix, int size)
{
    stack<char> exp;
    exp.push('#');
    int i = 0, j = 0;
    char *postfix = new char[size];
    while (i < size)
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
    return postfix;
}

int operation(char op, int x, int y)
{
    if (op == '+')
    {
        return x + y;
    }
    else if (op == '-')
    {
        return x - y;
    }
    else if (op == '*')
    {
        return x * y;
    }
    else if (op == '/')
    {
        return x / y;
    }
}

int evaluatePowstfix(char *postfix, int size)
{
    stack<int> expStack;
    int i = 0, x1 = 0, x2 = 0, r;
    while (i < size)
    {
        if (!isSymbol(postfix[i]))
        {
            expStack.push(postfix[i++] - '0');
        }
        else
        {
            x2 = expStack.top();
            expStack.pop();
            x1 = expStack.top();
            expStack.pop();

            r = operation(postfix[i], x1, x2);
            expStack.push(r);
            i++;
        }
    }
    r = expStack.top();
    expStack.pop();
    return r;
}
int main()
{
    string infix = "632-5*+1*7+";

    char *postfix = new char[infix.size() + 1];
    postfix = PostFix(infix, infix.size());
    int value=evaluatePowstfix(postfix,infix.size());
    cout<<value;
    return 0;
}