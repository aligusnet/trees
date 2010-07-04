#include "tree.hpp"
#include <vector>
#include <algorithm>

#define BOOST_TEST_MODULE testCalculator
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(testTree)

struct Fixture
{
  Fixture()
  {
    root = tree_node_new<int>();
    root->data = 0;
    TreeNode<int> *node1 = append_child(root, 1);
    /*TreeNode<int> *node2 = */append_child(root, 2);
    /*TreeNode<int> *node3 = */append_child(root, 3);
    /*TreeNode<int> *node4 = */append_child(node1, 4);
    TreeNode<int> *node5 = append_child(node1, 5);
    /*TreeNode<int> *node6 = */append_child(node5, 6);
    lst_preorder.push_back(0);
    lst_preorder.push_back(1);
    lst_preorder.push_back(4);
    lst_preorder.push_back(5);
    lst_preorder.push_back(6);
    lst_preorder.push_back(2);
    lst_preorder.push_back(3);
	  
		lst_postorder.push_back(4);
		lst_postorder.push_back(6);
		lst_postorder.push_back(5);
		lst_postorder.push_back(1);
		lst_postorder.push_back(2);
		lst_postorder.push_back(3);
		lst_postorder.push_back(0);
		
		lst_inorder.push_back(4);
		lst_inorder.push_back(1);
		lst_inorder.push_back(6);
		lst_inorder.push_back(5);
		lst_inorder.push_back(0);
		lst_inorder.push_back(2);
		lst_inorder.push_back(3);
  }

  ~Fixture()
  {
  }

  TreeNode<int> *root;
  std::vector<int> lst_preorder;
  std::vector<int> lst_postorder;
	std::vector<int> lst_inorder;
};

struct AppendFunc
{
  std::vector<int> lst_data;
  void operator () (int data)
  {
    lst_data.push_back(data);
  }
};

BOOST_FIXTURE_TEST_CASE(test_preorder_recursive, Fixture)
{
  AppendFunc func;
  preorder_recursive(root, func);
  BOOST_CHECK(std::equal(func.lst_data.begin(), func.lst_data.end(), lst_preorder.begin()));
}

BOOST_FIXTURE_TEST_CASE(test_preorder2, Fixture)
{
  AppendFunc func;
  preorder2(root, func);
  BOOST_CHECK(std::equal(func.lst_data.begin(), func.lst_data.end(), lst_preorder.begin()));
}

BOOST_FIXTURE_TEST_CASE(test_preorder3, Fixture)
{
	AppendFunc func;
	preorder3(root, func);
	BOOST_CHECK(std::equal(func.lst_data.begin(), func.lst_data.end(), lst_preorder.begin()));
}

BOOST_FIXTURE_TEST_CASE(test_postorder_recursive, Fixture)
{
  AppendFunc func;
  postorder_recursive(root, func);
  BOOST_CHECK(std::equal(func.lst_data.begin(), func.lst_data.end(), lst_postorder.begin()));
}

BOOST_FIXTURE_TEST_CASE(test_inorder_recursive, Fixture)
{
  AppendFunc func;
  inorder_recursive(root, func);
  BOOST_CHECK(std::equal(func.lst_data.begin(), func.lst_data.end(), lst_inorder.begin()));
}



BOOST_AUTO_TEST_SUITE_END()
