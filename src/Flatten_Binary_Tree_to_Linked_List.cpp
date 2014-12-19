// Source : https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Author : zheng yi xiong 
// Date   : 2014-12-19

/********************************************************************************** 
* 
* Given a binary tree, flatten it to a linked list in-place.

* For example,
* Given

*       1
*      / \
*     2   5
*    / \   \
*   3   4   6
* The flattened tree should look like:
*   1
*    \
*     2
*      \
*       3
*        \
*         4
*          \
*           5
*            \
*             6
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
    void flatten(TreeNode *root) {
        stack<TreeNode *> stack_pNode;
		TreeNode *pNode = root;
		while (NULL != pNode)
		{
			if (NULL != pNode->right)
			{
				stack_pNode.push(pNode->right);
			}

			if (NULL != pNode->left)
			{
				pNode->right = pNode->left;
				pNode->left = NULL;
			}
			else
			{
				if (!stack_pNode.empty())
				{
					pNode->right = stack_pNode.top();
					stack_pNode.pop();
				}
			}
			pNode = pNode->right;

			if ( (NULL == pNode) && (!stack_pNode.empty()))
			{
				pNode = stack_pNode.top();
				stack_pNode.pop();
			}
		}
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);
	TreeNode node4(4);
	TreeNode node5(5);
	TreeNode node6(6);
	node1.left = &node2;
	node1.right = &node5;
	node2.left = &node3;
	node2.right = &node4;
	node5.right = &node6;
	Solution so;
	so.flatten(&node1);
	return 0;
}

