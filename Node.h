#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

template <typename T>

class Node{
	public:
		Node();
		void setVal(T);
		void setNode(Node *);
		T value;
		Node *next;
		
};
#endif

template <typename T>
Node<T>::Node()
{
}

template <typename T>
void Node<T>::setVal(T v)
{
	value = v;
}

template <typename T>
void Node<T>::setNode(Node * n)
{
	next = n;
}
