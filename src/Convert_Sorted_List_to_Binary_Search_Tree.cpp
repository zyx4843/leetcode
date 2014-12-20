// Source : https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
// Author : zheng yi xiong 
// Date   : 2014-12-20

/********************************************************************************** 
* 
* Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	void LinkBST(vector<TreeNode *> &vec_tree_node, int begin, int end, TreeNode *&pTreeNode)
	{
		if (end == begin)
		{
			pTreeNode = vec_tree_node[begin];
			return;
		}
		int mid = (begin + end) / 2;
		pTreeNode = vec_tree_node[mid];
		if (mid > begin)
		{
			LinkBST(vec_tree_node, begin, mid - 1, pTreeNode->left);
		}

		LinkBST(vec_tree_node, mid + 1, end, pTreeNode->right);
	}
public:
	TreeNode *sortedListToBST(ListNode *head) {
		if (NULL == head)
		{
			return NULL;
		}
		vector<TreeNode *> vec_tree_node;
		ListNode *pTemListNode = head;
		TreeNode *pTreeNode = NULL;
		while (NULL != pTemListNode)
		{
			pTreeNode = new TreeNode(pTemListNode->val);
			vec_tree_node.push_back(pTreeNode);
			pTemListNode = pTemListNode->next;
		}

		int num = vec_tree_node.size();
		pTreeNode = NULL;
		LinkBST(vec_tree_node, 0, num - 1, pTreeNode);

		return pTreeNode;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 8;
	if ( argc > 1) {
		n = _wtoi(argv[1]);
	}

	ListNode *pListNode = new ListNode(1);
	ListNode *pTemListNode = pListNode;
	for (int i = 2; i < n; ++i)
	{
		pTemListNode->next = new ListNode(i);
		pTemListNode = pTemListNode->next;
	}

	Solution so;
	TreeNode *pTreeNode = so.sortedListToBST(pListNode);
	return 0;
}

