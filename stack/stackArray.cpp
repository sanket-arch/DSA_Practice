#include <iostream>
using namespace std;

class Stack
{
    int size;
    int top;
    int *s;

public:
    Stack(int x) // constructor to instialize the top,and declare array of size x
    {
        top = -1;
        size = x;
        s = new int[size];
    }
    ~Stack()
    {
        delete[] s;
    }
    bool isEmpty(); // this function will check whether stack is empty or not
    bool isFull();  // this function will check whether stack is full or not
    void push(int val);
    void pop();
    int peek(Stack &stack, int position);
    void show();
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
void Stack::push(int val)
{
    if (!isFull())
    {
        top++;
        s[top] = val;
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
        cout << s[top--] << endl;
    }
}
int Stack::peek(Stack &stack, int position)
{
    int index = stack.top - position + 1; // this this formula for finiding index in stack which
                                          // is implemenbted using array
    int x = -1;
    if (index < 0)
    {
        cout << "invalid stack position " << position << endl;
    }
    else
    {
        x = stack.s[index];
    }
    return x;
}
void Stack::show()
{
    for (int i = top; i >= 0; i--)
    {
        cout << s[i] << " " << flush;
    }
    cout << endl;
}
int main()
{
    int size = 5;
    Stack st(size);
    st.push(10);
    st.push(12);
    st.push(9);
    st.push(8);
    st.push(3);
    st.show();
    cout << st.peek(st, 5);
    return 0;
}