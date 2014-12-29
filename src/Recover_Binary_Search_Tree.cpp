// Source : https://oj.leetcode.com/problems/recover-binary-search-tree/
// Author : zheng yi xiong 
// Date   : 2014-12-26

/********************************************************************************** 
* 
* Two elements of a binary search tree (BST) are swapped by mistake.

* Recover the tree without changing its structure.

* Note:
* A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	void PreorderTraversal(TreeNode *pNode)
	{
		if (NULL == pNode)
		{
			return;
		}

		PreorderTraversal(pNode->left);
		if (NULL != m_pPrvNode)
		{
			if (pNode->val < m_pPrvNode->val)
			{
				if (NULL == m_pSwapNode1)
				{
					m_pSwapNode1 = m_pPrvNode;
				}
				m_pSwapNode2 = pNode;
			}
		}
		m_pPrvNode = pNode;
		PreorderTraversal(pNode->right);
	}
public:
	void recoverTree(TreeNode *root) {
		m_pSwapNode1	= NULL;
		m_pSwapNode2	= NULL;
		m_pPrvNode		= NULL;
		PreorderTraversal(root);
		if (m_pSwapNode1 && m_pSwapNode2)
		{
			int temp_val		= m_pSwapNode1->val;
			m_pSwapNode1->val	= m_pSwapNode2->val;
			m_pSwapNode2->val	= temp_val;
		}
	}
private:
	TreeNode	*m_pSwapNode1;
	TreeNode	*m_pSwapNode2;
	TreeNode	*m_pPrvNode;
};

int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode node1(5);
	TreeNode node2_1(3);
	TreeNode node2_2(8);
	TreeNode node3_1(2);
	TreeNode node3_2(9);
	TreeNode node3_3(6);
	TreeNode node3_4(4);
	node1.left = &node2_1;
	node1.right = &node2_2;
	node2_1.left = &node3_1;
	node2_1.right = &node3_2;
	node2_2.left = &node3_3;
	node2_2.right = &node3_4;
	/***********************************/
	/*             5                   */
	/*           /   \                 */
	/*          3     8                */
	/*         / \   / \               */
	/*        2   9 6   4              */
	/***********************************/

	Solution so;
	so.recoverTree(&node1);

	return 0;
}

