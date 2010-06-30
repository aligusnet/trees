#pragma once

#include "node.hpp"
#include <assert.h>

template <typename T>
class Stack
{
	Node<T> *pointer_;

public:
	Stack():  pointer_(0)
	{}

	void push(const T &data)
	{
		Node<T> *node = node_new<T>();
		node->data = data;
		node->next = pointer_;
		pointer_ = node;
	}

	T &top()
	{
		assert(pointer_);
		return pointer_->data;
	}

	void pop()
	{
		assert(pointer_);
		Node<T> *node = pointer_;
		pointer_ = pointer_->next;
		node_free(node);
	}

	bool empty()
	{
		return pointer_ == 0;
	}
};

template <typename T>
void stack_push(Node<T> *&stack, const T &data)
{
	Node<T> *node = node_new<T>();
	node->data = data;
	node->next = stack;
	stack = node;
}
