// Source : https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
// Author : zheng yi xiong 
// Date   : 2014-12-16

/********************************************************************************** 
* 
* Follow up for problem "Populating Next Right Pointers in Each Node".

* What if the given tree could be any binary tree? Would your previous solution still work?

* Note:

* You may only use constant extra space.
* For example,
* Given the following binary tree,
*        1
*      /  \
*     2    3
*    / \    \
*   4   5    7
* After calling your function, the tree should look like:
*       1 -> NULL
*     /  \
*    2 -> 3 -> NULL
*   / \    \
*  4-> 5 -> 7 -> NULL
*             
**********************************************************************************/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (NULL == root)
		{
			return;
		}

        if (NULL != root->right)
        {
			TreeLinkNode *pTemp = root->next;
			while (NULL != pTemp)
			{
				if (NULL != pTemp->left)
				{
					root->right->next = pTemp->left;
					break;
				}
				else if (NULL != pTemp->right)
				{
					root->right->next = pTemp->right;
					break;
				}
				pTemp = pTemp->next;
			}
			connect(root->right);
        }

		if (NULL != root->left)
		{
			if (NULL != root->right)
			{
				root->left->next = root->right;
			}
			else
			{
				TreeLinkNode *pTemp = root->next;
				while (NULL != pTemp)
				{
					if (NULL != pTemp->left)
					{
						root->left->next = pTemp->left;
						break;
					}
					else if (NULL != pTemp->right)
					{
						root->left->next = pTemp->right;
						break;
					}
					pTemp = pTemp->next;
				}
			}
			connect(root->left);
		}
    }
};