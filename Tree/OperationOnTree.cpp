#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

class tree
{
    Node *root;

public:
    tree();
    Node *createTree(int A[], int N);
    void preorder(Node *rootNode);

    // Operations
    int MaxDepth(Node *p);
    bool checkForBalancedBt(Node *p); // O(N^2)
    bool checkForBalanced(Node *p);   // O(N)

    int findDiameter(); // O(N);
};
tree::tree()
{
    root = nullptr;
}

Node *tree::createTree(int A[], int N)
{
    Node *p;
    Node *q;
    for (int i = 0; i < N; i++)
    {
        Node *temp = new Node;
        temp->left = temp->right = nullptr;
        temp->data = A[i];
        if (root == nullptr)
        {
            root = temp;
        }
        else
        {
            p = root;
            while (p)
            {
                q = p;
                if (p->data < A[i])
                    p = p->right;
                else if (p->data > A[i])
                    p = p->left;
                else
                    break;
            }
            if (q->data > A[i])
                q->left = temp;
            else
                q->right = temp;
        }
    }
    return root;
}

void tree::preorder(Node *rootNode)
{
    if (rootNode)
    {

        preorder(rootNode->left);
        preorder(rootNode->right);
        cout << rootNode->data << " ";
    }
}
int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

int tree::MaxDepth(Node *p)
{
    if (p == nullptr)
        return 0;
    else
    {
        int leftHeight = MaxDepth(p->left);
        int rightHeight = MaxDepth(p->right);
        return 1 + max(leftHeight, rightHeight);
    }
}

// This is O(N^2) solution.
bool tree::checkForBalancedBt(Node *p)
{
    if (p == nullptr)
        return true;
    int leftHeight = MaxDepth(p->left);
    int rightHeight = MaxDepth(p->right);

    if (abs(leftHeight - rightHeight) > 1)
        return false;

    bool left = checkForBalancedBt(p->left);
    bool right = checkForBalancedBt(p->right);

    if (!left || !right)
        return false;
    return true;
}

// Improved solution for Checking balanced tree;
// It will take O(N) time because we are visiting each node only once and checking only once
int dfHeight(Node *p)
{
    if (p == nullptr)
        return true;
    else
    {
        int left = dfHeight(p->left);
        int right = dfHeight(p->right);

        if (left == -1 || right == -1)
            return false;
        if (abs(left - right) > 1)
            return -1;
        return 1 + max(left, right);
    }
}

bool tree::checkForBalanced(Node *p)
{
    return dfHeight(p) != -1;
}


int findMaxDist(Node *p, int &diameter)
{
    if (p == nullptr)
        return 0;
    int left = findMaxDist(p->left, diameter);
    int right = findMaxDist(p->right, diameter);

    diameter = max(diameter, left + right);

    return 1 + max(left, right);
}
int tree::findDiameter()
{
    int diameter = 0;
    findMaxDist(root, diameter);
    return diameter;
}

int main()
{
    tree Tree;
    int A[] = {4, 2, 8, 9, 10, 3, 25, 7};
    int size = sizeof(A) / sizeof(A[0]);

    Node *root = Tree.createTree(A, size);
    // Tree.preorder(root);
    // cout << Tree.MaxDepth(root);
    // cout << Tree.checkForBalanced(root);
    cout << Tree.findDiameter();
    return 0;
}