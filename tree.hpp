#pragma once

#include "stack.hpp"

template <typename T>
struct TreeNode
{
	T data;
	TreeNode *parent;
	TreeNode *left_child;
	TreeNode *right_sibling;
};

template <typename T>
TreeNode<T> *tree_node_new()
{
	TreeNode<T> *node = new TreeNode<T>;
	node->parent = NULL;
	node->left_child = NULL;
	node->right_sibling = NULL;
	return node;
}

template <typename T>
void tree_node_free(TreeNode<T> *node)
{
	delete node;
}

template <typename T>
class Tree
{
public:
};

template <typename T>
TreeNode<T> *append_child(TreeNode<T> *node, const T &data)
{
	TreeNode<T> *child = tree_node_new<T>();
	child->data = data;
	child->parent = node;
	if(node->left_child == NULL)
	{
		node->left_child = child;
	}
	else
	{
		TreeNode<T> *curr_child = node->left_child;
		while(curr_child->right_sibling != NULL)
		{
			curr_child = curr_child->right_sibling;
		}
		curr_child->right_sibling =  child;
	}
	return child;
}

template <typename T, typename Func>
void preorder(TreeNode<T> *root, Func op)
{
	op(root->data);
	TreeNode<T> *child = root->left_child;
	while(child)
	{
		preorder(child, op);
		child = child->right_sibling;
	}
}

template <typename T, typename Func>
void preorder2(TreeNode<T> *root, Func op)
{
	Stack<TreeNode<T> *> stack;
	stack.push(root);
	while(!stack.empty())
	{
		TreeNode<T> *node = stack.top();
		op(node->data);
		stack.pop();
		if(node->right_sibling)
		{
			stack.push(node->right_sibling);
		}
		if(node->left_child)
		{
			stack.push(node->left_child);
		}
	}
}

