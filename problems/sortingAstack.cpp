#include <bits/stdc++.h>
using namespace std;
stack<int> sort()
{
    stack<int> tempStack;
    stack<int>s;

    while(!s.empty())
    {
        int currentPop=s.top();
        s.pop();
        while(!tempStack.empty() || currentPop<tempStack.top())
        {
            s.push(tempStack.top());
            tempStack.pop();
        }
        tempStack.push(currentPop);
    }

    while(!tempStack.empty())
    {
        s.push(tempStack.top());
        tempStack.pop();
    }
}
int main()
{
    return 0;
}