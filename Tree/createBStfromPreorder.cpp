#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

Node *createpre(int pre[], int n)
{
    stack<Node *> stk;
    Node *temp;
    int i = 0;
    Node *root = new Node;
    root->data = pre[i++];
    root->left = root->right = nullptr;
    Node *p = root;

    while (i < n)
    {

        if (pre[i] < p->data)
        {
            temp = new Node;
            temp->data = pre[i++];
            temp->left = temp->right = nullptr;
            p->left = temp;
            stk.push(p);
            p = temp;
        }
        else
        {
            if (pre[i] > p->data && pre[i] < stk.empty() ? 32767 : stk.top()->data)
            {
                temp = new Node;
                temp->data = pre[i++];
                temp->left = temp->right = nullptr;
                p->right = temp;
                p = temp;
            }
            else
            {
                p = stk.top();
                stk.pop();
            }
        }
    }
    return root;
}

void preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
}
int main()
{
    int A[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int size = sizeof(A) / sizeof(A[0]);
    Node *root = createpre(A, size);
    preorder(root);
    return 0;
}