// Source : https://oj.leetcode.com/problems/path-sum-ii/
// Author : zheng yi xiong 
// Date   : 2014-12-19

/********************************************************************************** 
* 
* Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

* For example:
* Given the below binary tree and sum = 22,
*        5
*       / \
*      4   8
*     /   / \
*    11  13  4
*   /  \    / \
*  7    2  5   1
* return
* [
*   [5,4,11,2],
*   [5,8,4,5]
* ]
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
	typedef struct _path_node_
	{
		TreeNode	*pTree;
		int			prev_sum;
		int			depth;
	}PATH_NODE;
public:
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int> > ret_vec;
		stack<PATH_NODE> stack_node;
		vector<int> vec_root;
		TreeNode *pNode = root;
		int node_sum = 0, depth = 0;
		while (NULL != pNode)
		{
			++depth;
			vec_root.push_back(pNode->val);
			node_sum += pNode->val;
			if (NULL != pNode->left)
			{
				if (NULL != pNode->right)
				{
					PATH_NODE path_node;
					path_node.pTree = pNode->right;
					path_node.prev_sum = node_sum;
					path_node.depth = depth;
					stack_node.push(path_node);
				}
				pNode = pNode->left;
			}
			else if (NULL != pNode->right)
			{
				pNode = pNode->right;
			}
			else
			{
				if (node_sum == sum)
				{
					ret_vec.push_back(vec_root);
				}

				if (!stack_node.empty())
				{
					PATH_NODE path_node = stack_node.top();
					stack_node.pop();
					pNode = path_node.pTree;
					node_sum = path_node.prev_sum;
					depth = path_node.depth;
					vec_root.resize(depth);
				}
				else
				{
					break;
				}
			}
		}

		return ret_vec;
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
	TreeNode node4_4(5);
	node1.left = &node2_1;
	node1.right = &node2_2;
	node2_1.left = &node3_1;
	node2_2.left = &node3_2;
	node2_2.right = &node3_3;
	node3_1.left = &node4_1;
	node3_1.right = &node4_2;
	node3_3.right = &node4_3;
	node3_3.left = &node4_4;
	Solution so;
	vector<vector<int> > ret_vec = so.pathSum(&node1, 22);

	return 0;
}

