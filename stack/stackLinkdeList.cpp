#include <iostream>
using namespace std;
class node // this class will be used to create or say define structure of node in linked list
{
public:
    int data;
    node *next;
};
class stack // used to to create stack
{
private:
    node *top; // pointer to the top node which will be null if no elemnet is present in linked list

public:
    stack()
    {
        top = nullptr; // top will point to the null as when first stack is created using
                       // linked list ther will be no element present in the stack
    }
    void push(int x);
    int pop();
    void display();
};
void stack::push(int x)
{
    node *temp = new node;
    if (temp == nullptr) // here we will check for over flow condition
                         // we try to crate a node and if node failed to create then it will denote that stack is full already
    {
        cout << "stack is full";
    }
    else
    {
        temp->data = x;
        temp->next = top;
        top = temp;
    }
}
int stack::pop()
{
    int x = -1; // used for storing poped value
    if (top == nullptr) //underflow condition
    {
        cout << "stack is empty";
    }
    else
    {
        node *temp = top;
        x=temp->data;
        top = top->next;
        delete temp;
    }
    return x;
}

void stack::display()
{
    node *p = top;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int main()
{
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(3);
    st.display();
    cout << st.pop()<<endl;
    st.display();
    return 0;
}