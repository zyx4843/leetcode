// Source : https://oj.leetcode.com/problems/maximum-depth-of-binary-tree/
// Author : zheng yi xiong 
// Date   : 2014-12-25

/********************************************************************************** 
* 
* Given a binary tree, find its maximum depth.

* The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*               
**********************************************************************************/
#include "stdafx.h"
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxDepth(TreeNode *root) {
		if (NULL == root)
		{
			return 0;
		}

		int leftDepth = 0, rightDepth = 0;
		if (NULL != root->left)
		{
			leftDepth = maxDepth(root->left);
		}

		if (NULL != root->right)
		{
			rightDepth = maxDepth(root->right);
		}

		return leftDepth > rightDepth ? (leftDepth + 1) : (rightDepth + 1);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode root(9);
	TreeNode node2(6);
	TreeNode node3(-3);
	TreeNode node4(-6);
	TreeNode node5(2);
	TreeNode node6(2);
	TreeNode node7(-6);
	TreeNode node8(-6);
	root.left = &node2;
	root.right = &node3;
	node3.left = &node4;
	node3.right = &node5;
	node5.left = &node6;
	node6.left = &node7;
	node6.right = &node8;
	Solution solution;
	int max_depth = solution.maxDepth(&root);

	return 0;
}

