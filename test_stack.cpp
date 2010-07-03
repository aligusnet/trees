#include "stack.hpp"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_stack)

BOOST_AUTO_TEST_CASE(simple_stack)
{
	Stack<int> stack;
	stack.push(0);
	stack.push(1);
	stack.push(2);
	BOOST_CHECK_EQUAL(stack.top(), 2);
	stack.push(3);
	stack.pop();
	stack.push(4);
	stack.push(5);
	stack.pop();
	BOOST_CHECK_EQUAL(stack.top(), 4);
	stack.pop();
	stack.pop();
	BOOST_CHECK_EQUAL(stack.top(), 1);
	stack.pop();
	stack.pop();
	BOOST_CHECK(stack.empty());
}

BOOST_AUTO_TEST_SUITE_END()