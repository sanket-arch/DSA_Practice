#include <iostream>
using namespace std;
class node
{
public:
    node *prev; // this pounter will point on the previous node
    int val;    // store the value to be stored at that node
    node *nxt;  // this will point to the next node
};

// crating a doubly linked list
node *create(int A[], int size)
{
    node *head, *p; // pointer to head and a temporary pointer to iterate through LL
    for (int i = 0; i < size; i++)
    {
        node *temp;
        temp = new node;
        temp->val = A[i];
        if (i == 0) // this will handle for the first element of the array
        {
            temp->prev = nullptr;
            temp->nxt = nullptr;
            head = temp;
            p = temp;
        }
        else
        {
            temp->prev = p;
            p->nxt = temp;
            p = temp;
            temp->nxt = nullptr;
        }
    }

    return head;
}

node *insertNode(node *head, int val, int pos)
{
    node *temp = new node;
    node *p = head;
    temp->val = val;
    if (p == nullptr) // when list is empty
    {
        temp->prev = nullptr;
        temp->nxt = nullptr;
        head = temp;
    }

    else if (pos == 1) // element to be inserted at first poisition
    {
        temp->nxt = head;
        temp->prev = nullptr;
        head->prev = temp;
        head = temp;
    }
    else
    {
        for (int i = 0; i < pos - 2; i++)
        {
            p = p->nxt;
        }
        temp->prev = p;
        if (p->nxt)
        {
            temp->nxt = p->nxt;
            p->nxt->prev = temp;
        }
        else // when node will be inserted at last
        {
            temp->nxt = nullptr;
        }
        p->nxt = temp;
    }

    return head;
}
node *deleteNode(node *head, int pos)
{
    node *p = head;

    if (pos == 1) //deleting first element
    {
        head = head->nxt;
        head->prev = nullptr;
        p->nxt = nullptr;
        delete p;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->nxt;
        }
        p->prev->nxt = p->nxt; //when eleement is last,p->nxt will be null hence it p->prev->nxt will be assigned null
        if (p->nxt) //when elemenet is not last
        {
            p->nxt->prev = p->prev;
        }
        delete p;
    }

    return head;
}
int main()
{
    int A[] = {4, 7, 2, 9, 1, 5};
    int size = sizeof(A) / sizeof(A[0]);

    node *head = create(A, size);
    node *p = head;

    // head = insertNode(head, 40, 3);
    // p = head;

    head = deleteNode(head, 6);
    p = head;
    while (p != nullptr)
    {
        cout << p->val << " ";
        p = p->nxt;
    }
    return 0;
}