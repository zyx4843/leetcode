// Source : https://oj.leetcode.com/problems/rotate-list/
// Author : zheng yi xiong 
// Date   : 2015-02-05

/********************************************************************************** 
* 
* Given a list, rotate the list to the right by k places, where k is non-negative.

* For example:
* Given 1->2->3->4->5->NULL and k = 2,
* return 4->5->1->2->3->NULL.
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (0 == k || NULL == head)
        {
			return head;
        }

		ListNode *pNode = head, *pRotate = head;
		int len = 1;
		while (pNode->next) {
			len++;
			pNode = pNode->next;
		}
		k = len - k % len;
		pNode->next = head;

		for(int step = 0; step < k; step++) {
			pNode = pNode->next;
		}
		head = pNode->next;
		pNode->next = NULL;

		return head;
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
	ListNode *pHead = so.rotateRight(&node1, 2);
	return 0;
}

