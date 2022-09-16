#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s1;
    stack<int> s2;
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(A) / sizeof(A[0]);
    int x = 5;
    for (int i = 0; i < size; i++)
    {
        s1.push(A[i]);
    }
    while (s1.top() != x)
    {
        s2.push(s1.top());
        s1.pop();
    }
    s2.push(s1.top());
    s1.pop();
    s2.pop();

    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }

    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }
    return 0;
}
