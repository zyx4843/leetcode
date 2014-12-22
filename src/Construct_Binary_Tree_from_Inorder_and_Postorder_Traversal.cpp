// Source : https://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Author : zheng yi xiong 
// Date   : 2014-12-20

/********************************************************************************** 
* 
* Given inorder and postorder traversal of a tree, construct the binary tree.

* Note:
* You may assume that duplicates do not exist in the tree.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	TreeNode *RightSonTree(vector<int> &inorder, int &i, vector<int> &postorder, int &j, int parent_val)
	{
		TreeNode *pLeft = NULL, *pRoot = NULL;
		if (inorder[i] == postorder[j])
		{
			pRoot = new TreeNode(inorder[i++]);
			++j;
		}

		while (parent_val != postorder[j])
		{
			pLeft = pRoot;

			pRoot = new TreeNode(inorder[i]);
			pRoot->left = pLeft;
			if (inorder[i] == postorder[j])
			{
				++i;
				++j;
			}
			else
			{
				++i;
				pRoot->right = RightSonTree(inorder, i, postorder, j, inorder[i - 1]);
			}
		}
		++j;

		return pRoot;
	}
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		if (inorder.empty())
		{
			return NULL;
		}

		int i = 0, j = 0;
		TreeNode *pLeft = NULL, *pRoot = NULL;
		if (inorder[i] == postorder[j])
		{
			pRoot = new TreeNode(inorder[i++]);
			++j;
		}

		while (i < inorder.size()) 
		{
			pLeft = pRoot;

			pRoot = new TreeNode(inorder[i]);
			pRoot->left = pLeft;
			if (inorder[i] == postorder[j])
			{
				++i;
				++j;
			}
			else
			{
				++i;
				pRoot->right = RightSonTree(inorder, i, postorder, j, inorder[i - 1]);
			}
		}

		return pRoot;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	int inorder_array[] = {8, 4, 9, 2, 10, 5, 11, 1, 12, 6, 13, 3, 14, 7, 15};
	int postorder_array[] = {8, 9, 4, 10, 11, 5, 2, 12, 13, 6, 14, 15, 7, 3, 1};
	vector<int> inorder(inorder_array, inorder_array + 15);
	vector<int> postorder(postorder_array, postorder_array + 15);
	Solution so;
	TreeNode *pRoot = so.buildTree(inorder, postorder);
	return 0;
}

