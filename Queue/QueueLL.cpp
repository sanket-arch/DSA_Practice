#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class QueueLL
{
private:
    node *front;
    node *rear;

public:
    QueueLL()
    {
        front = rear = nullptr;
    }
    bool isEmpty();
    bool isFull();
    void enqueue(int val);
    void dequeue();
    void display();
};

bool QueueLL::isEmpty()
{
    if (front == NULL)
        return true;
    else
        return false;
}
bool QueueLL::isFull()
{
    return false;
}
void QueueLL::enqueue(int val)
{
    if (isFull())
    {
        cout << "Queue is already full";
    }
    else
    {
        node *temp = new node;
        temp->data = val;
        temp->next = nullptr;
        if (front == NULL)
        {
            front = temp;
            rear = temp;
        }

        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
}
void QueueLL::dequeue()
{
    node *temp = front;
    front = front->next;
    delete temp;
}
void QueueLL::display()
{
    node *p = front;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(A) / sizeof(A[0]);
    QueueLL Q;
    for (int i = 0; i < size; i++)
    {
        Q.enqueue(A[i]);
    }
    Q.display();
    Q.dequeue();
    Q.display();
    return 0;
}