// Source : https://oj.leetcode.com/problems/unique-binary-search-trees-ii/
// Author : zheng yi xiong 
// Date   : 2014-12-29

/********************************************************************************** 
* 
* Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

* For example,
* Given n = 3, your program should return all 5 unique BST's shown below.

*   1         3     3      2      1
*    \       /     /      / \      \
*     3     2     1      1   3      2
*    /     /       \                 \
*   2     1         2                 3
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
public:
	vector<TreeNode *> generateTrees(int n) {
		if (n < 1)
		{
			vector<TreeNode *> ret_tree;
			ret_tree.push_back(NULL);
			return ret_tree;
		}

		return RecursionTrees(1, n);
	}
private:
	vector<TreeNode *> RecursionTrees(int start, int end)
	{
		vector<TreeNode *> vec_tree;
		if (start == end)
		{
			TreeNode *pNode = new TreeNode(start);
			vec_tree.push_back(pNode);
			return vec_tree;
		}

		vector<TreeNode *> vec_end = RecursionTrees(start, end - 1);
		for (int i = 0; i < vec_end.size(); ++i)
		{
			TreeNode *pNode = new TreeNode(end);
			pNode->left = vec_end[i];
			vec_tree.push_back(pNode);
		}

		vector<TreeNode *> vec_start = RecursionTrees(start + 1, end);
		for (int i = 0; i < vec_start.size(); ++i)
		{
			TreeNode *pNode = new TreeNode(start);
			pNode->right = vec_start[i];
			vec_tree.push_back(pNode);
		}

		for (int i = start + 1; i < end; ++i)
		{
			vector<TreeNode *> vec_left = RecursionTrees(start, i - 1);
			vector<TreeNode *> vec_right = RecursionTrees(i + 1, end);
			for (int left = 0; left < vec_left.size(); ++left)
			{
				for (int right = 0; right < vec_right.size(); ++right)
				{
					TreeNode *pNode = new TreeNode(i);
					pNode->left = vec_left[left];
					pNode->right = vec_right[right];
					vec_tree.push_back(pNode);
				}
			}
		}

		return vec_tree;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 3;
	if ( argc > 1) {
		n = _wtoi(argv[1]);
	}

	Solution so;
	vector<TreeNode *> trees = so.generateTrees(n);

	return 0;
}

