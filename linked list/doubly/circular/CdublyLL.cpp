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
            temp->nxt = head;
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
        head = temp;
        temp->prev = head;
        temp->nxt = head;
    }

    else if (pos == 1) // element to be inserted at first poisition (WARNING: This block is not working for Cdoubly LL,need to fixed)
    {
        temp->nxt = head;
        temp->prev = head->prev;
        head->prev = temp;
        temp->prev->nxt = temp;
    }
    else
    {
        for (int i = 0; i < pos - 2; i++)
        {
            p = p->nxt;
        }
        temp->prev = p;
        if (p->nxt != head)
        {
            temp->nxt = p->nxt;
            p->nxt->prev = temp;
        }
        else // when node will be inserted at last
        {
            temp->nxt = p->nxt;
            p->nxt->prev = temp;
        }
        p->nxt = temp;
    }

    return head;
}

node *deleteNode(node *head, int pos)
{
    node *p = head;

    if (pos == 1) // deleting first element(WARNING: This block is not working for Cdoubly LL,need to fixed)
    {
        head = head->nxt;
        head->prev = p->prev;
        p->prev->nxt = p->nxt;
        delete p;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->nxt;
        }
        p->prev->nxt = p->nxt; // when eleement is last,p->nxt will be null hence it p->prev->nxt will be assigned null
        p->nxt->prev = p->prev;

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

    // head = insertNode(head, 40, 1);
    // p = head;

    head = deleteNode(head, 4);
    p = head;
    do
    {
        cout << p->val << " ";
        p = p->nxt;
    } while (p != head);
    return 0;
}