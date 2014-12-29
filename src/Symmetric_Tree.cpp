// Source : https://oj.leetcode.com/problems/symmetric-tree/
// Author : zheng yi xiong 
// Date   : 2014-12-26

/********************************************************************************** 
* 
* Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

* For example, this binary tree is symmetric:

*      1
*     / \
*    2   2
*   / \ / \
*  3  4 4  3
* But the following is not:
*     1
*    / \
*   2   2
*    \   \
*    3    3
* Note:
*  Bonus points if you could solve it both recursively and iteratively.
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
private:
	bool IsEqual(TreeNode *pLeft, TreeNode *pRight)
	{
		if (NULL == pLeft)
		{
			if (NULL == pRight)
			{
				return true;
			}
			return false;
		}
		else if (NULL == pRight)
		{
			return false;
		}

		if (pLeft->val != pRight->val)
		{
			return false;
		}

		if (!IsEqual(pLeft->left, pRight->right))
		{
			return false;
		}

		if (!IsEqual(pLeft->right, pRight->left))
		{
			return false;
		}

		return true;
	}
public:
	bool isSymmetric(TreeNode *root) {
		if (NULL == root)
		{
			return false;
		}

		return IsEqual(root->left, root->right);
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

	Solution so;
	bool bSymmetric = so.isSymmetric(&node1);

	return 0;
}

