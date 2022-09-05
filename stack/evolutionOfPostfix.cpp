// This code is not working properly need to be fixed
#include <iostream>
#include <stack>
using namespace std;
bool isSymbol(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '\\')
        return true;
    else
        return false;
}
int prec(char symbol)
{
    if (symbol == '+' || symbol == '-')
        return 1;
    else if (symbol == '*' || symbol == '\\')
        return 2;
    else
        return 0;
}

char *PostFix(char *infix, int size)
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
int main()
{
    char infix[] = "6+5*3-4\\2";
    int size = sizeof(infix) / sizeof(infix[0]);
    int i = 0, x1 = 0, x2 = 0, r;
    stack<int> expStack;
    char *postfix = new char[size];
    postfix = PostFix(infix, size);
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

            r = operation(postfix[i++], x1, x2);
            expStack.push(r);
        }
    }
    r = expStack.top();
    expStack.pop();
    cout << r;
    // while (!expStack.empty())
    // {
    //     cout << expStack.top();
    //     expStack.pop();
    // }
    cout<<"level";
    return 0;
}