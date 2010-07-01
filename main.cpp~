#include <iostream>

#include "stack.hpp"

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

int main(int argc, char **argv)
{
	test_stack();
	return 0;
}
