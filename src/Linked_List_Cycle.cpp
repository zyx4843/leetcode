// Source : https://oj.leetcode.com/problems/linked-list-cycle/
// Author : zheng yi xiong 
// Date   : 2014-11-28

/********************************************************************************** 
* 
* Given a linked list, determine if it has a cycle in it.

* Follow up:
* Can you solve it without using extra space?
*               
**********************************************************************************/
#include "stdafx.h"
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class CLinked_List_Cycle {
public:
	bool hasCycle(ListNode *head) {
		if (NULL == head)
		{
			return false;
		}

		ListNode *pNode1 = head;
		ListNode *pNode2 = head;

		do 
		{
			pNode1 = pNode1->next;
			if (NULL == pNode2->next)
			{
				return false;
			}
			pNode2 = pNode2->next->next;

			if (pNode1 == pNode2)
			{
				return true;
			}
		} while (NULL != pNode2);

		return false;
	}
};