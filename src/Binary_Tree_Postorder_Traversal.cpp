// Source : https://oj.leetcode.com/problems/binary-tree-postorder-traversal/
// Author : zheng yi xiong 
// Date   : 2014-11-22

/********************************************************************************** 
* 
* Given a binary tree, return the postorder traversal of its nodes' values.

* For example:
* Given binary tree {1,#,2,3},
* 1
*  \
*   2
*  /
* 3
* return [3,2,1].

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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> postorder_vec;
		if (NULL == root)
		{
			return postorder_vec;
		}

		stack<TreeNode *> postorder_stack;
		vector<bool>		bVisit_vec;		//if visit stack node
		postorder_stack.push(NULL);
		postorder_stack.push(root);
		bVisit_vec.push_back(false);
		TreeNode *pTempNode = postorder_stack.top();
		int visit_index = 0;
		while (NULL != pTempNode)
		{
			if ( (bVisit_vec[visit_index]) || ((NULL == pTempNode->right) && (NULL == pTempNode->left)) )
			{
				postorder_vec.push_back(pTempNode->val);
				postorder_stack.pop();
				bVisit_vec.pop_back();
				--visit_index;
			}
			else
			{
				bVisit_vec[visit_index] = true;
				if (NULL != pTempNode->right)
				{
					postorder_stack.push(pTempNode->right);
					bVisit_vec.push_back(false);
					++visit_index;
				}

				if (NULL != pTempNode->left)
				{
					postorder_stack.push(pTempNode->left);
					bVisit_vec.push_back(false);
					++visit_index;
				}
			}

			pTempNode = postorder_stack.top();
		}

		return postorder_vec;
    }
};