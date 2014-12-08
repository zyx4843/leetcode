// Source : https://oj.leetcode.com/problems/linked-list-cycle-ii/
// Author : zheng yi xiong 
// Date   : 2014-12-03

/********************************************************************************** 
* 
* Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

* Follow up:
* Can you solve it without using extra space?
*               
**********************************************************************************/
#include "stdafx.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class CLinked_List_Cycle_II {
public:
    ListNode *detectCycle(ListNode *head) {
        if (NULL == head)
		{
			return NULL;
		}

		ListNode *pNode1 = head;
		ListNode *pNode2 = head;

		do 
		{
			pNode1 = pNode1->next;
			if (NULL == pNode2->next)
			{
				return NULL;
			}
			pNode2 = pNode2->next->next;

			if (pNode1 == pNode2)
			{
				pNode2 = head;
				while (pNode1 != pNode2)
				{
					pNode1 = pNode1->next;
					pNode2 = pNode2->next;
				}

				return pNode1;
			}

		} while (NULL != pNode2);

		return NULL;
    }
};