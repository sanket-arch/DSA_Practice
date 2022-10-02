#include <iostream>
#include <stack>
using namespace std;
bool ispar(string x)
{
    stack<char> stk;
    int i = 0;
    if (x.size() == 1 || x[i] == '}' || x[i] == ']' || x[i] == ')')
    {
        return false;
    }
    else
    {
        while (i < x.size())
        {
            if (x[i] == '{' || x[i] == '[' || x[i] == '(')
                stk.push(x[i++]);
            else
            {
                if (stk.empty())
                {
                    return false;
                }
               
                if (x[i] == '}' && stk.top() == '{' || x[i] == ')' && stk.top() == '(' || x[i] == ']' && stk.top() == '[')
                {
                    stk.pop();
                    i++;
                }
                else
                    return false;
            }
        }
    }
    if (stk.empty())

        return true;

    else
        return false;
}
int main()
{
    string exp = "())}}({)[]}{]([[}(]][[()()()]}]}]{[))}}[(]]{([(}]((}][[[{[()()(]}}})}])()[})[}}})(([(){{}({[}(((]}}}(]{(][{({[)([)][)(}({}{{[{((}(}[{(]{]]]]((})[{(][]{})}{{}]({(](}[){){)())(}([){({}}}[}}{((){]{){{])[";
    cout << ispar(exp);
    return 0;
}