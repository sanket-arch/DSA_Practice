#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *nxt;
};

node *create(int A[], int size)
{
    node *head = new node;
    node *temp; // this poinnter will be used for creating a temp. node and later link this node to the previous node
    node *last; // this will always point to the previous node

    // creating first elemnt of the list
    head->data = A[0];
    head->nxt = nullptr; // pointing to null as no data is after head right now
    last = head;         // last pointer pointing to the head element

    for (int i = 1; i < size; i++)
    {
        temp = new node;     // crate an new temp node
        temp->data = A[i];   // assign data to the temp node
        temp->nxt = nullptr; // pointing to the null as no element is after this element right now

        last->nxt = temp; // linking the temp node the previous node by assigning the address of temp
        last = temp;      // node last is pointing to the new node which is temp;
    }
    return head;
}

node *midNode(node *head)
{
    node *p, *q;
    p = q = head;
    while (q)
    {
        q = q->nxt; //first jump
        if (q) //if p is not already null then only q and p will make next jump
        {
            q = q->nxt;
            p = p->nxt;
        }
    }
    return p;
}
int main()
{
    int A[] = {1};
    int size = sizeof(A) / sizeof(A[0]);
    node *head = create(A, size);

    node *mid = midNode(head);

    cout << mid->data;
    return 0;
}