// Source : https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/
// Author : zheng yi xiong 
// Date   : 2014-12-19

/********************************************************************************** 
* 
* Given a binary tree, find its minimum depth.

* The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
public:
    int minDepth(TreeNode *root) {
		if (NULL == root)
		{
			return 0;
		}

        int min_depth = 0, parent_num = 1, son_num = 0;
		queue<TreeNode *> queue_node;
		queue_node.push(root);
		TreeNode *pNode = NULL;
		while (!queue_node.empty())
		{
			pNode = queue_node.front();
			queue_node.pop();
			if (NULL == pNode->left && NULL == pNode->right)
			{
				++min_depth;
				break;
			}

			if (NULL != pNode->left)
			{
				queue_node.push(pNode->left);
				++son_num;
			}

			if (NULL != pNode->right)
			{
				queue_node.push(pNode->right);
				++son_num;
			}

			--parent_num;
			if (0 == parent_num)
			{
				++min_depth;
				parent_num = son_num;
				son_num = 0;
			}
		}

		return min_depth;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode node1(5);
	TreeNode node2_1(4);
	TreeNode node2_2(8);
	TreeNode node3_1(11);
	TreeNode node3_2(13);
	TreeNode node3_3(4);
	TreeNode node4_1(7);
	TreeNode node4_2(2);
	TreeNode node4_3(1);
	node1.left = &node2_1;
	node1.right = &node2_2;
	node2_1.left = &node3_1;
	node2_2.left = &node3_2;
	node2_2.right = &node3_3;
	node3_1.left = &node4_1;
	node3_1.right = &node4_2;
	node3_3.right = &node4_3;

	Solution so;
	int min_depth = so.minDepth(&node1);
	return 0;
}

