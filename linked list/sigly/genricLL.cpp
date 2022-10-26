#include <bits/stdc++.h>
using namespace std;
template <class T>
class Node
{
public:
	T data;
	Node *next;
};
template <class T>
class LinkedList
{
	Node<T> *head;
	Node<T> *temp;
	Node<T> *last;

public:
	LinkedList();
	Node<T> *traverse(T pos);
	Node<T> *insert(T val);
	Node<T> *insert(T val, int pos);
	void del();
	void del(int pos);
	void display();
};
template <class T>
Node<T> *LinkedList<T>::traverse(T pos)
{
	Node<T> *p = head;
	int i = 0;
	while (i != pos)
	{
		p = p->next;
		i++;
	}

	return p;
}
template <class T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	last = nullptr;
}

template <class T>
Node<T> *LinkedList<T>::insert(T val, int pos)
{
	Node<T> *p = traverse(pos);
	Node<T> *temp = new Node<T>;
	temp->data=val;
	if (p == head)
	{
		temp->next=head;
		head=temp;
	}
	else if(p==last)
	{
		temp->next=nullptr;
		p->next=temp;
		last=temp;
	}
	else{
		temp->next=p->next;
		p->next=temp;
	}
}
template <class T>
Node<T> *LinkedList<T>::insert(T val)
{
	temp = new Node<T>;
	temp->data = val;
	temp->next = nullptr;
	if (head == nullptr)
	{
		head = temp;
		last = temp;
	}
	else
	{
		last->next = temp;
		last = temp;
	}
	return head;
}
template<class T>
void LinkedList<T>::del(int pos)
{
Node<T> *p=traverse(pos-1);
if (head == nullptr)
	{
		cout << "list is empty";
	}
	else if (head == last)
	{
		cout << "delted item is" << head->data;
		head = nullptr;
		last = head;
	}
	else
	{	
		Node<T> *q=	p->next;
		cout << "delted item is " << q->data << endl;
		p->next=q->next;
		delete q;
	}
}
template <class T>
void LinkedList<T>::del()
{
	if (head == nullptr)
	{
		cout << "list is empty";
	}
	else if (head == last)
	{
		cout << "delted item is" << head->data;
		head = nullptr;
		last = head;
	}
	else
	{
		Node<T> *p = head;
		Node<T> *deltNode = last;

		while (p->next->next != nullptr)
		{
			p = p->next;
		}
		p->next = nullptr;
		cout << "delted item is " << last->data << endl;
		last = p;
		delete deltNode;
	}
}

template <class T>
void LinkedList<T>::display()
{
	Node<T> *p = head;

	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
int main()
{
	LinkedList<int> LL;

	LL.insert(10);
	LL.insert(20);
	LL.insert(40);
	LL.display();
	LL.insert(5,0);
	LL.display();
	LL.del(2);
	LL.display();
	return 0;
}
