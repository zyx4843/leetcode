// Source : https://oj.leetcode.com/problems/insertion-sort-list/
// Author : zheng yi xiong 
// Date   : 2014-11-21

/********************************************************************************** 
* 
* Sort a linked list using insertion sort.
*               
**********************************************************************************/

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if ( (NULL == head) || (NULL == head->next) )
		{
			return head;
		}
		
        ListNode *pSortHead = head;
		ListNode *pSortTail = head;
		ListNode *pPos = head->next;
		ListNode *pTemp = NULL, *pSortPos = NULL;

		while (NULL != pPos)
		{
			if (pPos->val < pSortHead->val)
			{
				pTemp = pSortHead;
				pSortHead = pPos;
				pPos = pPos->next;
				pSortHead->next = pTemp;
			}
			else if (pPos->val >= pSortTail->val)
			{
				pSortTail->next = pPos;
				pSortTail = pPos;
				pPos = pPos->next;
			}
			else
			{
				pSortPos = pSortHead;
				while ( (pSortPos->next != pSortTail) && (pSortPos->next->val < pPos->val) )
				{
					pSortPos = pSortPos->next;
				}

				pTemp = pSortPos->next;
				pSortPos->next = pPos;
				pPos = pPos->next;
				pSortPos->next->next = pTemp;
			}
		}

		pSortTail->next = NULL;
		return pSortHead;
    }
};