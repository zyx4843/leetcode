// Source : https://oj.leetcode.com/problems/merge-two-sorted-lists/
// Author : zheng yi xiong 
// Date   : 2015-02-05

/********************************************************************************** 
* 
* Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (NULL == l1)
		{
			return l2;
		}

		if (NULL == l2)
		{
			return l1;
		}

        ListNode root(0);
		ListNode *pNode = &root;
		while (NULL != l1 && NULL != l2)
		{
			if (l1->val < l2->val)
			{
				pNode->next = l1;
				l1 = l1->next;
			}
			else
			{
				pNode->next = l2;
				l2 = l2->next;
			}

			pNode = pNode->next;
		}

		if (NULL != l1)
		{
			pNode->next = l1;
		}
		else
		{
			pNode->next = l2;
		}

		return root.next;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

