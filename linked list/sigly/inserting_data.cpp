#include <iostream>
using namespace std;
class node // strcuture for node
{
public:
    int data;
    node *nxt;
};

node *create(int A[], int size) // cration of node
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

void insertElement(node *head, int pos, int val)
{
    node *t = new node; // create a node that need to be inserted
    t->data = val;
    // Here x will be used to navigate to the position
    node *x = head;                   // here numbering if index will start from 1
    for (int i = 1; i < pos - 1; i++) // reach the position where node need to be inserted
    {
        x = x->nxt;
    }
    // x pointer reached the postion
    t->nxt = x->nxt; // first t will point the next node i.e node after the inserted node
    x->nxt = t;      // then prev node will point to the current node here
}

// extending List  y isnerting at last
node *createListeByInserting(int num)
{ // initially both first and last will point to the null
    node *first = nullptr;
    node *last = nullptr;
    int i = 1;
    while (i <= num)
    {
        node *temp = new node; // creating a new node to be inserted
        cout << "insert data";
        cin >> temp->data;
        temp->nxt = nullptr;
        if (first == nullptr) // this will handle the case when no element in the list
        {
            first = temp;
            last = temp;
        }
        else
        {
            last->nxt = temp;
            last = temp;
        }
        i++;
    }
    return first;
}


//inserting element in sorted linked list

void sortedInsert(node *p,int val)
{
    node *t,*q=nullptr;
    t=new node;
    t->data=val;
    t->nxt=nullptr;

    while(p && p->data<val)
    {
        q=p;
        p=p->nxt;
    }
    if(p->nxt=nullptr)
    {
        t->nxt=p;

    }
    else{
        t->nxt=q->nxt;
        q->nxt=t;
    }
}
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    node *p = create(A, 5);
    node *x = p;
    cout << "before insertion" << endl;
    while (p != nullptr)
    {
        cout << p->data << endl;
        p = p->nxt;
    }

    insertElement(x, 6, 30);
    cout << "after insertion" << endl;
    while (x != nullptr)
    {
        cout << x->data << endl;
        x = x->nxt;
    }

    // creating by insertion
    int num;
    cout << "how many element";
    cin >> num;

    node *point = createListeByInserting(num);
    while (point != nullptr)
    {
        cout << point->data << endl;
        point = point->nxt;
    }

    return 0;
}