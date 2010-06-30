#pragma once

//Node
template <typename T> struct Node
{
	T data;
	Node *next;
};

template <typename T> 
Node<T> *node_new()
{
	Node<T> *node = new Node<T>();
	return node;
}

template <typename T> 
void node_free(Node<T> *node)
{
	delete node;
}
