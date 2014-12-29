// Source : https://oj.leetcode.com/problems/same-tree/
// Author : zheng yi xiong 
// Date   : 2014-12-26

/********************************************************************************** 
* 
* Given two binary trees, write a function to check if they are equal or not.

* Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSameTree(TreeNode *p, TreeNode *q) {
		if ( (NULL == p) && (NULL == q) )
		{
			return true;
		}

		if ( (NULL == p) || (NULL == q) )
		{
			return false;
		}

		if (p->val != q->val)
		{
			return false;
		}

		if (!isSameTree(p->left, q->left))
		{
			return false;
		}

		if (!isSameTree(p->right, q->right))
		{
			return false;
		}

		return true;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode node1(1);
	TreeNode node2_1(2);
	TreeNode node2_2(2);
	TreeNode node3_1(3);
	TreeNode node3_2(4);
	TreeNode node3_3(4);
	TreeNode node3_4(3);
	node1.left = &node2_1;
	node1.right = &node2_2;
	node2_1.left = &node3_1;
	node2_1.right = &node3_2;
	node2_2.left = &node3_3;
	node2_2.right = &node3_4;

	TreeNode node_1(1);
	TreeNode node_2_1(2);
	TreeNode node_2_2(2);
	TreeNode node_3_1(3);
	TreeNode node_3_2(4);
	TreeNode node_3_3(4);
	TreeNode node_3_4(3);
	node_1.left = &node_2_1;
	node_1.right = &node_2_2;
	node_2_1.left = &node_3_1;
	node_2_1.right = &node_3_2;
	node_2_2.left = &node_3_3;
	node_2_2.right = &node_3_4;

	Solution so;
	bool bSame = so.isSameTree(&node1, &node_1);

	return 0;
}

