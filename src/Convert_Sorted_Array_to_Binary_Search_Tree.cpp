// Source : https://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Author : zheng yi xiong 
// Date   : 2014-12-20

/********************************************************************************** 
* 
* Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
	void LinkBST(vector<int> &vec_number, int begin, int end, TreeNode *&pTreeNode)
	{
		if (end == begin)
		{
			pTreeNode = new TreeNode(vec_number[begin]);
			return;
		}
		int mid = (begin + end) / 2;
		pTreeNode = new TreeNode(vec_number[mid]);
		if (mid > begin)
		{
			LinkBST(vec_number, begin, mid - 1, pTreeNode->left);
		}

		LinkBST(vec_number, mid + 1, end, pTreeNode->right);
	}
public:
	TreeNode *sortedArrayToBST(vector<int> &num) {
		if (num.empty())
		{
			return NULL;
		}
		TreeNode *pTreeNode = NULL;
		int len = num.size();
		pTreeNode = NULL;
		LinkBST(num, 0, len - 1, pTreeNode);

		return pTreeNode;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 8;
	if ( argc > 1) {
		n = _wtoi(argv[1]);
	}

	vector<int> num;
	for (int i = 1; i < n; ++i)
	{
		num.push_back(i);
	}

	Solution so;
	TreeNode *pTreeNode = so.sortedArrayToBST(num);
	return 0;
}

