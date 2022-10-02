#include <bits/stdc++.h>
using namespace std;

int findMaxLen(string s)
{
    stack<char> stk;
    int i = 0, count = 0, pushed = 0, max = 0;
    if (s.size() == 1)
        return count;
    else
    {
        while (i < s.size())
        {
            if (s[i] == '(')
            {
                stk.push(s[i++]);
                pushed++;
            }

            else
            {
                if (pushed == 0)
                    i++;
                else if (stk.empty())
                {
                    if (count > max)
                    {
                        max = count;
                        count = 0;
                        i++;
                    }
                }
                else
                {
                    stk.pop();
                    count += 2;
                    i++;
                }
            }
        }
    }
    if(count>max)
    {
        max=count;
    }
    return max;
}
int main()
{
    string s = "))))()())()()()()";
    cout << findMaxLen(s);
    return 0;
}