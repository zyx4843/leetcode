// Source : https://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Author : zheng yi xiong 
// Date   : 2014-12-22

/********************************************************************************** 
* 
* Given preorder and inorder traversal of a tree, construct the binary tree.

* Note:
* You may assume that duplicates do not exist in the tree.
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
private:
	TreeNode *LeftSonTree(vector<int> &preorder, int &pre_pos, vector<int> &inorder, int &in_pos, int parent_val)
	{
		TreeNode *pRight = NULL, *pRoot = NULL;
		if (inorder[in_pos] == preorder[pre_pos])
		{
			pRoot = new TreeNode(inorder[in_pos--]);
			--pre_pos;
		}

		while (parent_val != preorder[pre_pos])
		{
			pRight = pRoot;

			pRoot = new TreeNode(inorder[in_pos]);
			pRoot->right = pRight;
			if (inorder[in_pos] == preorder[pre_pos])
			{
				--in_pos;
				--pre_pos;
			}
			else
			{
				--in_pos;
				pRoot->left = LeftSonTree(preorder, pre_pos, inorder, in_pos, inorder[in_pos + 1]);
			}
		}
		--pre_pos;

		return pRoot;
	}
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		if (inorder.empty())
		{
			return NULL;
		}

		int pre_pos = preorder.size() - 1;
		int in_pos = pre_pos;
		TreeNode *pRight = NULL, *pRoot = NULL;
		if (inorder[in_pos] == preorder[pre_pos])
		{
			pRoot = new TreeNode(inorder[in_pos--]);
			--pre_pos;
		}

		while (0 <= in_pos) 
		{
			pRight = pRoot;

			pRoot = new TreeNode(inorder[in_pos]);
			pRoot->right = pRight;
			if (inorder[in_pos] == preorder[pre_pos])
			{
				--in_pos;
				--pre_pos;
			}
			else
			{
				--in_pos;
				pRoot->left = LeftSonTree(preorder, pre_pos, inorder, in_pos, inorder[in_pos + 1]);
			}
		}

		return pRoot;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int inorder_array[] = {8, 4, 9, 2, 10, 5, 11, 1, 12, 6, 13, 3, 14, 7, 15};
	int preorder_array[] = {1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 12, 13, 7, 14, 15};
	vector<int> inorder(inorder_array, inorder_array + 15);
	vector<int> preorder(preorder_array, preorder_array + 15);
	Solution so;
	TreeNode *pRoot = so.buildTree(preorder, inorder);

	return 0;
}

