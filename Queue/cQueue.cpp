// to make queue ciurcular then we have to use modulus operation
#include <bits/stdc++.h>
using namespace std;
class circularQueue
{
private:
    int size;
    int front;
    int rear;
    int *cq;

public:
    circularQueue(int n)
    {
        size = n + 1;
        front = rear = 0;
        cq = new int[size];
    }
    bool isEmpty();
    bool isFull();
    void enqueue(int val);
    void dequeue();
    void display();
};
bool circularQueue::isFull()
{
    if ((rear + 1) % size == front)
        return true;
    else
        return false;
}
bool circularQueue::isEmpty()
{
    if (front == rear)
        return true;
    else
        return false;
}
void circularQueue::enqueue(int val)
{
    if (isFull())
        cout << "queue is full";
    else
    {
        rear = (rear + 1) % size;
        cq[rear] = val;
    }
}

void circularQueue::dequeue()
{
    if (isEmpty())
        cout << "queue is empty";
    else
    {
        front = (front + 1) % size;
        int x = cq[front];
    }
}
void circularQueue::display()
{
    int i = front + 1; //since box which front pointing is empty, we have to start one plus
    do
    {
        cout << cq[i] << flush << " ";
        i = (i + 1) % size;  //using modulus 
    } while (i != (rear + 1) % size);  //when i reach reach
    cout << endl;
}
int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(A) / sizeof(A[0]);
    circularQueue cq(size);
    for (int i = 0; i < size; i++)
    {
        cq.enqueue(A[i]);
    }
    cq.display();
    cq.dequeue();
    cq.display();
    cq.enqueue(1);
    cq.display();
    return 0;
}