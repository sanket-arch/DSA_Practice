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
    head->nxt = head; // pointing to null as no data is after head right now
    last = head;      // last pointer pointing to the head element

    for (int i = 1; i < size; i++)
    {
        temp = new node;       // crate an new temp node
        temp->data = A[i];     // assign data to the temp node
        temp->nxt = last->nxt; // pointing to the null as no element is after this element right now
        last->nxt = temp;      // linking the temp node the previous node by assigning the address of temp
        last = temp;           // node last is pointing to the new node which is temp;
    }
    return head;
}

void insertNode(node *head, int pos, int val)
{
    node *p = head;
    node *temp;
    temp = new node;
    temp->data = val;
    temp->nxt = nullptr;
    if (pos == 1)
    {
        if (head == nullptr)
        {
            head = temp;
        }
        while (p->nxt != head)
        {
            p = p->nxt;
        }
        p->nxt = temp;
        temp->nxt = head;
        head = temp;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->nxt;
        }
        temp->nxt = p->nxt;
        p->nxt = temp;
    }
}
// This function is not working i dont know why

// void deleteNodeByValue(node *head, int val)
// {
//     node *p = head;
//     node *q;

//     while (p->data != val || p->nxt != head)
//     {
//         q = p;
//         p = p->nxt;
//     }
//     if (p->data == val)
//     {
//         q->nxt = p->nxt;
//         p->nxt = nullptr;
//         delete p;
//     }
//     else
//     {
//         cout << "data doesnot exist";
//     }
// }

node *deleteNodeByPos(node *head, int pos, int size)
{
    node *p = head;
    node *q;
    if (pos == 1)
    {
        while (p->nxt != head)
        {
            p = p->nxt;
        }
        if (p == head)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            p->nxt = head->nxt;
            delete head;
            head = p->nxt;
        }
    }
    else if (pos <= size)
    {
        for (int i = 0; i < pos - 2; i++)
        {
            p = p->nxt;
        }
        q = p->nxt;
        p->nxt = q->nxt;
        q->nxt = nullptr;
        delete q;
    }
    else
    {
        cout << "out of boundary";
    }
    return head;
}
int main()
{
    int A[] = {2};
    int size = 1;
    node *head = create(A, size);
    node *p = head;
    cout << "original list" << endl;
    do
    {
        cout << p->data << "  ";
        p = p->nxt;
    } while (p != head);

    insertNode(head, 3, 40);
    size++;
    cout << endl;
    cout<<"List after insertion"<<endl;
    do
    {
        cout << p->data << "  ";
        p = p->nxt;
    } while (p != head);

    head = deleteNodeByPos(head, 1, size);
    p = head;
    cout << endl;
    cout << "list after deletion" << endl;
    if (p == nullptr)
    {
        cout << "empty list";
    }
    else
    {
        do
        {
            cout << p->data << "  ";
            p = p->nxt;
        } while (p != head);
    }

    return 0;
}