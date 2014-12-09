// Source : https://oj.leetcode.com/problems/sum-root-to-leaf-numbers/
// Author : zheng yi xiong 
// Date   : 2014-12-09

/********************************************************************************** 
* 
* Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

* An example is the root-to-leaf path 1->2->3 which represents the number 123.

* Find the total sum of all root-to-leaf numbers.

* For example,

*    1
*   / \
*  2   3
* The root-to-leaf path 1->2 represents the number 12.
* The root-to-leaf path 1->3 represents the number 13.

* Return the sum = 12 + 13 = 25.
*               
**********************************************************************************/
#include "stdafx.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class CSum_Root_to_Leaf_Numbers {
private:
	void CalculateTreeNode(TreeNode *&pNode, int &parentNumber, int &sum)
	{
		int node_number = parentNumber * 10 + pNode->val;
		if ( (NULL == pNode->left) && (NULL == pNode->right) )
		{
			sum += node_number;
			return;
		}

		if (NULL != pNode->left)
		{
			CalculateTreeNode(pNode->left, node_number, sum);
		}

		if (NULL != pNode->right)
		{
			CalculateTreeNode(pNode->right, node_number, sum);
		}
	}
public:
    int sumNumbers(TreeNode *root) {
        if (NULL == root)
        {
			return 0;
        }

		int sum = 0, parent_number = 0;
		CalculateTreeNode(root, parent_number, sum);

		return sum;
    }
};