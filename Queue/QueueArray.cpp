#include <bits/stdc++.h>
using namespace std;

class queueClass
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    queueClass(int n)
    {
        size = n;
        rear = front = -1;
        Q = new int[size];
    }
    bool isEmpty();
    bool isFull();
    void enque(int val);
    void dequeue();
    void display();
};
bool queueClass::isEmpty()
{
    if (rear == front)//This condition for empty to be followed when front point on the one before the first element OF queue
    // if(rear>front)  This condition will be used when front will point on the first element of queue
        return true;
    else
        return false;
}
bool queueClass::isFull()
{
    if (rear == size - 1) 
        return true;
    else
        return false;
}
void queueClass::enque(int val)
{
    if (isFull())
    {
        cout << "Queue is already full";
    }
    else
    {
        rear++;
        Q[rear] = val;
    }
}
void queueClass::display()
{
    for (int i = front + 1; i <= rear; i++)
    {
        cout << Q[i] << flush << " ";
    }
    cout << endl;
}
void queueClass::dequeue(){
    if(isEmpty())
    {
        cout<<"queue is empty";
    }
    else{
        front++;
        cout<<Q[front]<<endl;
    }
}
int main()
{
    int A[] = {10, 35, 1, 67, 45, 9};
    int size = sizeof(A) / sizeof(A[0]);
    queueClass queObj(size);
    queObj.enque(10);
    queObj.display();
   
    
    return 0;
}