// Source : https://oj.leetcode.com/problems/balanced-binary-tree/
// Author : zheng yi xiong 
// Date   : 2014-12-20

/********************************************************************************** 
* 
* Given a binary tree, determine if it is height-balanced.

* For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
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
	int TreeDepth(TreeNode *pNode, bool &bBalanced)
	{
		if (!bBalanced)
		{
			return 0;
		}

		int left_depth = 0, right_depth = 0;
		if (NULL != pNode->left)
		{
			left_depth = TreeDepth(pNode->left, bBalanced);
		}

		if (NULL != pNode->right)
		{
			right_depth = TreeDepth(pNode->right, bBalanced);
		}

		if (bBalanced)
		{
			int div_depth = left_depth - right_depth;
			if ( 1 < div_depth || -1 > div_depth)
			{
				bBalanced = false;
			}
		}

		return left_depth > right_depth ? (left_depth + 1) : (right_depth + 1);
	}
public:
	bool isBalanced(TreeNode *root) {
		if (NULL == root)
		{
			return true;
		}
		bool bBalanced = true;
		int depth = TreeDepth(root, bBalanced);
		return bBalanced;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode node1(5);
	TreeNode node2_1(4);
	TreeNode node2_2(8);
	TreeNode node3_1(11);
	//TreeNode node3_2(13);
	TreeNode node3_3(4);
	TreeNode node4_1(7);
	TreeNode node4_2(2);
	TreeNode node4_3(1);
	node1.left = &node2_1;
	node1.right = &node2_2;
	node2_1.left = &node3_1;
	//node2_2.left = &node3_2;
	node2_2.right = &node3_3;
	node3_1.left = &node4_1;
	node3_1.right = &node4_2;
	node3_3.right = &node4_3;

	Solution so;
	bool bBalanced = so.isBalanced(&node1);

	return 0;
}

