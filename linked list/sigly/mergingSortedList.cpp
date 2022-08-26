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

node *merge(node *first, node *second)
{
    node *head = nullptr, *last = nullptr; // these pointer will keep track of head and and of the linked list

    if (first->data < second->data)
    {
        head = first;        // head will point to the  first element of first LL
        last = first;        // last will also point on the same as head because in first case both will pont on the same node
        first = first->nxt;  // here we are changing the starting node of first LL
        last->nxt = nullptr; // since it is the last element of LL it will point to the null
    }
    else // this block of code will do the same thing as above but it will do for the second LL
    {
        head = second;
        last = second;
        second = second->nxt;
        last->nxt = nullptr;
    }
    while (first != nullptr && second != nullptr) // it will start excuting from the second element whether of first of second LL
    {
        if (first->data > second->data)
        {
            last->nxt = second;   // link the current last element to the next big element
            last = second;        // now last will point on the positon where the next big element exist
            second = second->nxt; // now moving the pointer to the next elemnt of LL
            last->nxt = nullptr;  // now assigning the null pointer to the next pointer since it is last element it will not point  any element
        }
        else // this block of code will do the exact same thing as above but for other LL
        {
            last->nxt = first;
            last = first;
            first = first->nxt;
            last->nxt = nullptr;
        }
    }
    // this if...else clause will take care of the condition of termination of the above while loop
    //here we are just linking the last element with the remaning element
    if (first != nullptr)
    {
        last->nxt = first;
    }
    else
    {
        last->nxt = second;
    }
    return head;
}
int main()
{
    int A[] = {2, 8, 10, 15};
    int B[] = {4, 7, 12, 14};
    node *first = create(A, 4);
    node *second = create(B, 4);
    node *third = merge(first, second);

    while (third != nullptr)
    {
        cout << third->data << "  ";
        third = third->nxt;
    }
    return 0;
}