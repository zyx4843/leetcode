// Source : https://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/
// Author : zheng yi xiong 
// Date   : 2014-12-20

/********************************************************************************** 
* 
* Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

* For example:
* Given binary tree {3,9,20,#,#,15,7},
*    3
*   / \
*  9  20
*    /  \
*   15   7
* return its bottom-up level order traversal as:
* [
*   [15,7],
*   [9,20],
*   [3]
* ]
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	void levelOrder(vector<vector<int> > &vec_ret, int &vec_num, int level, TreeNode *pNode)
	{
		if (level < vec_num)
		{
			vec_ret[level].push_back(pNode->val);
		}
		else
		{
			vector<int> temp_vec;
			temp_vec.push_back(pNode->val);
			vec_ret.push_back(temp_vec);
			++vec_num;
		}

		if (pNode->left)
		{
			levelOrder(vec_ret, vec_num, level + 1, pNode->left);
		}

		if (pNode->right)
		{
			levelOrder(vec_ret, vec_num, level + 1, pNode->right);
		}
	}
public:
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > vec_ret;
		if (NULL != root)
		{
			int vec_num = 0, level = 0;
			levelOrder(vec_ret, vec_num, level, root);
			reverse(vec_ret.begin(), vec_ret.end());
		}

		return vec_ret;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode node1(3);
	TreeNode node2_1(9);
	TreeNode node2_2(20);
	TreeNode node3_1(15);
	TreeNode node3_2(7);
	/*TreeNode node3_3(4);
	TreeNode node4_1(7);
	TreeNode node4_2(2);
	TreeNode node4_3(1);*/
	node1.left = &node2_1;
	node1.right = &node2_2;
	node2_2.left = &node3_1;
	node2_2.right = &node3_2;
	/*node2_2.right = &node3_3;
	node3_1.left = &node4_1;
	node3_1.right = &node4_2;
	node3_3.right = &node4_3;*/

	Solution solution;
	vector<vector<int> > vec_ret = solution.levelOrderBottom(&node1);
	return 0;
}

