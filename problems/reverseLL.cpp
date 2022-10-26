#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
            struct node *prev=NULL;
        struct node *nxt=NULL;
        
        while(head !=NULL)
        {
            nxt=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        head=temp;
        
        return head;
    }
    
};
int main()
{
 return 0;
}