#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int value;
    TreeNode *lChild;
    TreeNode *rChild;
};

class BinarySearchTree
{
private:
    TreeNode *root;

public:
    TreeNode *insertRecursively(TreeNode *t, int key);
    TreeNode *insertIterative(TreeNode *t, int key);

    TreeNode *searchInTree(TreeNode *t, int key);          // recursicely
    TreeNode *searchInTreeItreative(TreeNode *t, int key); // iterative

    TreeNode *create(int A[], int n);

    TreeNode *deleteNode(TreeNode *t, int key);
    TreeNode *InPre(TreeNode *p);
    TreeNode *InSucc(TreeNode *p);
};

TreeNode *BinarySearchTree::insertRecursively(TreeNode *t, int key) // logn
{
    TreeNode *temp;
    if (t == nullptr)
    {
        temp = new TreeNode;
        temp->value = key;
        temp->lChild = temp->rChild = nullptr;
    }
    else if (key < t->value)
        t->lChild = insertRecursively(t->lChild, key);
    else
        t->rChild = insertRecursively(t->rChild, key);

    return t;
}

TreeNode *BinarySearchTree::insertIterative(TreeNode *t, int key)
{
    TreeNode *r = nullptr, *temp;
    while (t != nullptr)
    {
        r = t;
        if (key == t->value)
            return;
        else
        {
            if (key < t->value)
                t = t->lChild;
            else
                t = t->rChild;
        }
    }
    temp = new TreeNode;
    temp->value = key;
    temp->lChild = temp->rChild = nullptr;
    if (key < r->value)
        r->lChild = temp;
    else
        r->rChild = temp;

    return t;
}

TreeNode *BinarySearchTree::searchInTree(TreeNode *t, int key) // logn
{
    if (t == nullptr)
        return nullptr;
    else if (t->value == key)
        return t;
    else if (key < t->value)
        searchInTree(t->lChild, key);
    else
        searchInTree(t->rChild, key);
}

TreeNode *BinarySearchTree::searchInTreeItreative(TreeNode *t, int key)
{
    while (t)
    {
        if (t == nullptr)
            return nullptr;
        else if (t->value == key)
            return t;
        else if (key < t->value)
            t = t->lChild;
        else
            t = t->rChild;
    }

    return nullptr;
}

TreeNode *BinarySearchTree::create(int A[], int n) // time complexity is nlogn
{
    TreeNode *rootNode = nullptr;
    int i = 0;
    while (i < n)
    {
        TreeNode *t = root;
        insertIterative(t, A[i]);
        i++;
    }
    return rootNode;
}

TreeNode *BinarySearchTree::deleteNode(TreeNode *t, int key)
{
    TreeNode *q;
    if (t == nullptr)
        return nullptr;
    if (t->lChild == nullptr && t->rChild == nullptr)
    {
        if (t == root)
        {
            root = nullptr;
        }
        delete t;
        return nullptr;
    }
    else
    {
        q = InPre(t->lChild);
        t->value = q->value;
        t->lChild=deleteNode(t->lChild,q->value);
    }
}
TreeNode *BinarySearchTree::InPre(TreeNode *p)
{
    while (p && p->rChild != nullptr)
    {
        p = p->rChild;
    }
    return p;
}

TreeNode *BinarySearchTree::InSucc(TreeNode *p)
{
    while (p && p->lChild != nullptr)
    {
        p = p->lChild;
    }
    return p;
}

int main()
{

    return 0;
}