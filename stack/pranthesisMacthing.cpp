#include <bits/stdc++.h>
using namespace std;
class Stack
{
    int size;
    int top;
    char *s;

public:
    Stack(int x) // constructor to instialize the top,and declare array of size x
    {
        top = -1;
        size = x;
        s = new char[size];
    }
    ~Stack()
    {
        delete[] s;
    }
    bool isEmpty(); // this function will check whether stack is empty or not
    bool isFull();  // this function will check whether stack is full or not
    void push(char x);
    void pop();
    char stTop();
};
bool Stack::isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}
bool Stack::isFull()
{
    if (top == size - 1)
        return true;
    else
        return false;
}
char Stack::stTop()
{
    if (isEmpty())
    {
        return -1;
    }
    return s[top];
}
void Stack::push(char x)
{
    if (!isFull())
    {
        top++;
        s[top] = x;
    }
    else
    {
        cout << "overflow";
    }
}
void Stack::pop()
{
    if (isEmpty())
    {
        cout << "stack underflow";
    }
    else
    {
        s[top--];
    }
}

bool isBlance(string exp)
{
    Stack st(exp.length());

    for (int i = 0; i < exp.size(); i++)
    {
        if (exp[i] == '(')
        {
            st.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (st.isEmpty())
                return false;
            else if (exp[i] == ')')
                st.pop();
        }
    }
    return st.isEmpty() ? true : false;
}
int main()
{
    string exp = "x+(a*(b+c)-(c-d))";
    cout << isBlance(exp);
    return 0;
}