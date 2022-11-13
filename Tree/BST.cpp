#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *left;
    Node *right;
};

class Tree
{
    Node *root;

public:
    Tree() { root = nullptr; }
    Node *insert(int key);
    bool search(int key);

    Node *deleteNode(Node *p, int key);
    Node *InPre(Node *p);
    void inorder(Node *p);
    void postorder(Node *p);
    void preorder(Node *p);
};

Node *Tree::insert(int key)
{
    Node *p;
    Node *q;
    Node *temp = new Node;
    temp->left = temp->right = nullptr;
    temp->value = key;
    if (root == nullptr)
        root = temp;
    else
    {
        p = root;

        while (p)
        {
            q = p;
            if (key < p->value)
                p = p->left;
            else if (key > p->value)
                p = p->right;
            else
                break;
        }
        if (key < q->value)
            q->left = temp;
        else if (key > q->value)
            q->right = temp;
    }

    return root;
}

bool Tree::search(int key)
{
    Node *p = root;

    while (p)
    {
        if (key == p->value)
        {
            return true;
        }

        else if (key > p->value)
            p = p->right;
        else
            p = p->left;
    }
    return false;
}

Node *Tree::deleteNode(Node *p, int key)
{
    Node *q;
    if (p == nullptr)
    {
        return nullptr;
    }
    else if (p->left == nullptr && p->right == nullptr)
    {
        if (p == root)
        {
            root == nullptr;
        }
        delete p;
        return nullptr;
    }
    else if (key < p->value)
        p->left = deleteNode(p->left, key);
    else if (key > p->value)
        p->right = deleteNode(p->right, key);
    else
    {
        q = InPre(p->left);
        p->value = q->value;
        p->left = deleteNode(p->left, q->value);
    }
    return p;
}
Node *Tree::InPre(Node *p)
{
    while (p && p->right != nullptr)
    {
        p = p->right;
    }
    return p;
}
void Tree::inorder(Node *p)
{
    if (p)
    {
        inorder(p->left);
        cout << p->value << " ";
        inorder(p->right);
    }
}
void Tree::postorder(Node *p)
{
    if (p)
    {
        postorder(p->left);
        cout << p->value << " ";
        postorder(p->right);
    }
}
void Tree::preorder(Node *p)
{
    if (p)
    {
        preorder(p->left);
        cout << p->value << " ";
        preorder(p->right);
    }
}

int main()
{
    Tree bst;
    int A[] = {5, 2, 7, 12, 7, 8, 1, 14};
    int size = sizeof(A) / sizeof(A[0]);
    Node *root;
    for (int i = 0; i < size; i++)
    {
        root = bst.insert(A[i]);
    }
    bst.inorder(root);
    cout << endl;
    bst.deleteNode(root, 5);

    bst.inorder(root);
    return 0;
}