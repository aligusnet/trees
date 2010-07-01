#include <iostream>

#include "stack.hpp"
#include "tree.hpp"

void test_stack()
{
	Stack<int> stack;
	for(int i = 0; i < 10; ++i)
	{
		stack.push(i);
	}
	while(!stack.empty())
	{
		std::cout << stack.top() << " ";
		stack.pop();
	}
	std::cout << std::endl;
}

struct PrintFunc
{
	void operator () (int data)
	{
		std::cout << data << " ";
	}
};

void test_tree()
{
	TreeNode<int> *root = tree_node_new<int>();
	root->data = 0;
	TreeNode<int> *node1 = append_child(root, 1);
	TreeNode<int> *node2 = append_child(root, 2);
	TreeNode<int> *node3 = append_child(root, 3);
	TreeNode<int> *node4 = append_child(node1, 4);
	TreeNode<int> *node5 = append_child(node1, 5);
	TreeNode<int> *node6 = append_child(node5, 6);

	preorder2(root, PrintFunc());
}

int main(int argc, char **argv)
{
	//test_stack();
	test_tree();
	return 0;
}
