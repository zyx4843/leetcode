// Source : https://oj.leetcode.com/problems/binary-tree-preorder-traversal/
// Author : zheng yi xiong 
// Date   : 2014-11-22

/********************************************************************************** 
* 
* Given a binary tree, return the preorder traversal of its nodes' values.

* For example:
* Given binary tree {1,#,2,3},
* 1
*  \
*   2
*  /
* 3
* return [1,2,3].

* Note: Recursive solution is trivial, could you do it iteratively?
*               
**********************************************************************************/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
		vector<int> preorder_vec;
		if (NULL == root)
		{
			return preorder_vec;
		}

		stack<TreeNode *> preorder_stack;
		preorder_stack.push(NULL);
		TreeNode *pTempNode = root;
		while (NULL != pTempNode)
		{
			preorder_vec.push_back(pTempNode->val);
			if (NULL != pTempNode->right)
			{
				preorder_stack.push(pTempNode->right);
			}

			if (NULL != pTempNode->left)
			{
				pTempNode = pTempNode->left;
			}
			else
			{
				pTempNode = preorder_stack.top();
				preorder_stack.pop();
			}
		}

		return preorder_vec;
    }
};