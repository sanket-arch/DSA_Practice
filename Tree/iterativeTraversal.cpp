#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int value;
    TreeNode *lChild;
    TreeNode *rChild;
};

class node
{
public:
    TreeNode *data;
    node *next;
};
class QueueLL
{
private:
    node *front;
    node *rear;

public:
    QueueLL()
    {
        front = rear = nullptr;
    }
    bool isEmpty();
    bool isFull();
    void enqueue(TreeNode *val);
    TreeNode *top();
    void dequeue();
    void display();
};

bool QueueLL::isEmpty()
{
    if (front == NULL)
        return true;
    else
        return false;
}
bool QueueLL::isFull()
{
    return false;
}
void QueueLL::enqueue(TreeNode *val)
{
    if (isFull())
    {
        cout << "Queue is already full";
    }
    else
    {
        node *temp = new node;
        temp->data = val;
        temp->next = nullptr;
        if (front == NULL)
        {
            front = temp;
            rear = temp;
        }

        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
}
TreeNode *QueueLL::top()
{
    return front->data;
}
void QueueLL::dequeue()
{
    node *temp = front;
    front = front->next;
    delete temp;
}
void QueueLL::display()
{
    node *p = front;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

class Tree
{
private:
    TreeNode *root;

    QueueLL q;

public:
    Tree() { root = nullptr; }
    TreeNode *createTree(int value, int pos);
    void inorder(TreeNode *root);
    void postorder(TreeNode *root);
    void preorder(TreeNode *root);
    void levelOrder(TreeNode *temp);

    // iterative travesal
    void IterativeInorder(TreeNode *temp);
    void IterativePostorder(TreeNode *temp);
    void IterativePreorder(TreeNode *temp);
};

TreeNode *Tree::createTree(int value, int pos = -1)
{
    TreeNode *p, *temp;
    temp = new TreeNode;
    temp->value = value;
    temp->lChild = temp->rChild = nullptr;
    if (root == nullptr)
    {
        root = temp;
        q.enqueue(root);
    }
    else
    {
        // Enable while loop when u get array as a params

        // while (!q.isEmpty())
        // {
        p = q.top();
        q.dequeue();

        // inserting in left child
        if (pos == 0)
        {
            p->lChild = temp;
            q.enqueue(temp);
        }

        // inserting into right child
        else if (pos == 1)
        {
            p->rChild = temp;
            q.enqueue(temp);
        }
        // }
    }

    return root;
}

// left->node->right
void Tree::inorder(TreeNode *root)
{
    if (root == nullptr)
        return;

    inorder(root->lChild);
    cout << root->value << "  ";

    inorder(root->rChild);
}

// left->right->node
void Tree::postorder(TreeNode *root)
{
    if (root == nullptr)
        return;

    postorder(root->lChild);

    postorder(root->rChild);
    cout << root->value << "  ";
}

// node->left->right
void Tree::preorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->value << "  ";
    preorder(root->lChild);

    preorder(root->rChild);
}

// iterative inorder
void Tree::IterativeInorder(TreeNode *temp)
{
    stack<TreeNode *> stk;

    while (temp != nullptr || !stk.empty())
    {
        if (temp != nullptr)
        {
            stk.push(temp);
            temp = temp->lChild;
        }
        else
        {
            temp = stk.top();
            stk.pop();
            cout << temp->value << " ";
            temp = temp->rChild;
        }
    }
}

void Tree::IterativePreorder(TreeNode *temp)
{
    stack<TreeNode *> stk;

    while (temp != nullptr || !stk.empty())
    {
        if (temp != nullptr)
        {
            cout << temp->value << " ";
            stk.push(temp);
            temp = temp->lChild;
        }
        else
        {
            temp = stk.top();
            stk.pop();
            temp = temp->rChild;
        }
    }
}

void Tree::IterativePostorder(TreeNode *temp)
{
    stack<TreeNode *> stk;

    while (temp != nullptr || !stk.empty())
    {
        if (temp != nullptr)
        {
            stk.push(temp);
            temp = temp->lChild;
        }
        else
        {
            temp = stk.top();
            stk.pop();
            temp = temp->rChild;
        }
    }
}

// Levelorder
void Tree::levelOrder(TreeNode *temp)
{
    queue<TreeNode *> q;
    cout << temp->value;
    q.emplace(temp);  //emplace is used to add element at the end of the queue

    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->lChild != nullptr)
        {
            cout << temp->lChild->value;
            q.emplace(temp->lChild);
        }
        if(temp->rChild !=nullptr){
            cout<<temp->rChild->value;
            q.emplace(temp->rChild);
        }
    }
}

int main()
{
    Tree t;
    TreeNode *root = t.createTree(9);
    t.createTree(10, 0);
    t.createTree(20, 1);
    t.createTree(30, 1);
    t.createTree(40, 0);

    // t.inorder(root);
    cout << endl;
    // t.postorder(root);

    // cout << endl;
    // t.preorder(root);

    t.IterativePreorder(root);
    return 0;
}