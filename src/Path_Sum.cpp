// Source : https://oj.leetcode.com/problems/path-sum/
// Author : zheng yi xiong 
// Date   : 2014-12-19

/********************************************************************************** 
* 
* Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

* For example:
* Given the below binary tree and sum = 22,
*        5
*       / \
*      4   8
*     /   / \
*    11  13  4
*   /  \      \
*  7    2      1
* return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
		bool bHas = false;
        stack<int> stack_sum;
		stack<TreeNode *> stack_node;
		TreeNode *pNode = root;
		int node_sum = 0;
		while (NULL != pNode)
		{
			node_sum += pNode->val;
			if (NULL != pNode->left)
			{
				if (NULL != pNode->right)
				{
					stack_node.push(pNode->right);
					stack_sum.push(node_sum);
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
					bHas = true;
					break;
				}

				if (!stack_node.empty())
				{
					pNode = stack_node.top();
					stack_node.pop();
					node_sum = stack_sum.top();
					stack_sum.pop();
				}
				else
				{
					break;
				}
			}
		}

		return bHas;
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
	bool bHas = so.hasPathSum(&node1, 22);

	return 0;
}

