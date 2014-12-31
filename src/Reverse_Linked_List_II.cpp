// Source : https://oj.leetcode.com/problems/reverse-linked-list-ii/
// Author : zheng yi xiong 
// Date   : 2014-12-31

/********************************************************************************** 
* 
* Reverse a linked list from position m to n. Do it in-place and in one-pass.

* For example:
* Given 1->2->3->4->5->NULL, m = 2 and n = 4,

* return 1->4->3->2->5->NULL.

* Note:
* Given m, n satisfy the following condition:
* 1 ¡Ü m ¡Ü n ¡Ü length of list.
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

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
		if (m == n)
		{
			return head;
		}

        ListNode tempNode(0);
		tempNode.next = head;
		ListNode *pPrevM = &tempNode;
		for (int i = 0; i < m - 1; ++i)
		{
			pPrevM = pPrevM->next;
		}


		ListNode *pPrevN = pPrevM->next;
		if (n > m + 1)
		{
			for (int i = m; i < n - 1; ++i)
			{
				pPrevN = pPrevN->next;
			}

			ListNode *pNextM = pPrevM->next->next;
			ListNode *pNextNextM = NULL;
			pPrevM->next->next = pPrevN->next->next;
			pPrevN->next->next = NULL;

			while (NULL != pNextM)
			{
				pNextNextM = pNextM->next;
				pNextM->next = pPrevM->next;
				pPrevM->next = pNextM;
				pNextM = pNextNextM;
			}
		}
		else
		{
			ListNode *pNextn = pPrevN->next;
			pPrevN->next = pPrevN->next->next;
			pNextn->next = pPrevM->next;
			pPrevM->next = pNextn;
		}

		return tempNode.next;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);
	ListNode node4(4);
	ListNode node5(5);
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	Solution so;
	ListNode *pRoot = so.reverseBetween(&node1, 1, 3);
	return 0;
}

