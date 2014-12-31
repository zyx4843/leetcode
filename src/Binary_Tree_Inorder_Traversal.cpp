// Source : https://oj.leetcode.com/problems/binary-tree-inorder-traversal/
// Author : zheng yi xiong 
// Date   : 2014-12-30

/********************************************************************************** 
* 
* Given a binary tree, return the inorder traversal of its nodes' values.

* For example:
* Given binary tree {1,#,2,3},
*    1
*    \
*     2
*    /
*   3
* return [1,3,2].

* Note: Recursive solution is trivial, could you do it iteratively?
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> vec_inorder;
		if (NULL == root)
		{
			return vec_inorder;
		}

		stack<TreeNode *> stack_inorder;
		stack_inorder.push(root);
		TreeNode *pNode = root->left;
		while (!stack_inorder.empty() || NULL != pNode)
		{
			if (NULL == pNode)
			{
				pNode = stack_inorder.top();
				stack_inorder.pop();
				vec_inorder.push_back(pNode->val);
				pNode = pNode->right;
			}
			else
			{
				stack_inorder.push(pNode);
				pNode = pNode->left;
			}
		}

		return vec_inorder;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);
	node1.right = &node2;
	node2.left = &node3;
	Solution so;
	vector<int> ret_vec = so.inorderTraversal(&node1);
	return 0;
}

