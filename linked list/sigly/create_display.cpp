#include <bits/stdc++.h>
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

/* RECURSIVE APPROACH  to display a linked list */
// void display(node *p)
//  {
//      if (p != nullptr)
//      {
//          cout << p->data << "->" << flush;
//          display(p->nxt);
//      }
//  }

// Recursive approach to add elements
// int sum(node *p)
// {
//     if(p!=nullptr)
//     {
//         return sum(p->nxt)+p->data;
//     }
// }

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    int count = 0, sumEle = 0, maxelement = A[0];
    node *p = create(A, 5); // Here pointer p will point the head of the linked list
    // cout<<sum(p)<<endl;
    while (p != nullptr)
    {
        count++;
        maxelement = max(maxelement, p->data);
        cout << p->data << "->" << flush << endl;
        sumEle += p->data;
        p = p->nxt;
    }
    cout << "count=" << count << endl
         << "sum=" << sumEle << endl
         << "max=" << maxelement;

    return 0;
}