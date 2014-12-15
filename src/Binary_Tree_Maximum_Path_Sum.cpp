// Source : https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/
// Author : zheng yi xiong 
// Date   : 2014-12-15

/********************************************************************************** 
* 
* Given a binary tree, find the maximum path sum.

* The path may start and end at any node in the tree.

* For example:
* Given the below binary tree,

*   1
*  / \
* 2   3
* Return 6.
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
private:
	int maxSonPath(TreeNode *pParent, int &maxPath)
	{
		int maxSon = pParent->val;
		int leftPath = 0;
		int rightPath = 0;
		if (maxPath < pParent->val)
		{
			maxPath = pParent->val;
		}

		if (NULL != pParent->left)
		{
			leftPath = maxSonPath(pParent->left, maxPath);

			if (maxPath < leftPath + pParent->val)
			{
				maxPath = leftPath + pParent->val;
			}

			if (maxSon < leftPath + pParent->val)
			{
				maxSon = leftPath + pParent->val;
			}
		}

		if (NULL != pParent->right)
		{
			rightPath = maxSonPath(pParent->right, maxPath);

			if (maxPath < rightPath + pParent->val)
			{
				maxPath = rightPath + pParent->val;
			}

			if (maxSon < rightPath + pParent->val)
			{
				maxSon = rightPath + pParent->val;
			}
		}

		if (maxPath < leftPath + rightPath + pParent->val)
		{
			maxPath = leftPath + rightPath + pParent->val;
		}

		return maxSon;
	}
public:
	int maxPathSum(TreeNode *root) {
		if (NULL == root)
		{
			return 0;
		}

		int maxPath = root->val;

		int leftPath = 0;
		int rightPath = 0;
		if (NULL != root->left)
		{
			leftPath = maxSonPath(root->left, maxPath);

			if (maxPath < leftPath + root->val)
			{
				maxPath = leftPath + root->val;
			}
		}

		if (NULL != root->right)
		{
			rightPath = maxSonPath(root->right, maxPath);

			if (maxPath < rightPath + root->val)
			{
				maxPath = rightPath + root->val;
			}
		}

		if (maxPath < leftPath + rightPath + root->val)
		{
			maxPath = leftPath + rightPath + root->val;
		}

		return maxPath;
	}
};


