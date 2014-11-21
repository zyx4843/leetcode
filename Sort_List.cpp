// Source : https://oj.leetcode.com/problems/sort-list/
// Author : zheng yi xiong 
// Date   : 2014-11-21

/********************************************************************************** 
* 
* Sort a linked list in O(n log n) time using constant space complexity.
*               
**********************************************************************************/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  void quitSortList(ListNode *&begin, ListNode *&end)
	{
		if(end == begin)
		{
			return;
		}

		if(end == begin->next)
		{
			if(begin->val > end->val)
			{
				ListNode *pTemp = begin;
				begin = end;
				end = pTemp;
				begin->next = end;
			}

			return;
		}

		static ListNode scLeft(0);
		static ListNode scRight(0);
		ListNode *pLeft_begin = &scLeft, *pRight_begin = &scRight, *pLeft_end = &scLeft, *pRight_end = &scRight;
		ListNode *pPos = begin->next, *pMid_end = begin;

		while(end != pPos)
		{
			if(pPos->val < begin->val)
			{
				pLeft_end->next = pPos;
				pLeft_end = pPos;
			}
			else if (pPos->val == begin->val)
			{
				pMid_end->next = pPos;
				pMid_end = pPos;
			}
			else
			{
				pRight_end->next = pPos;
				pRight_end = pPos;
			}
			pPos = pPos->next;
		}

		if(pPos->val < begin->val)
		{
			pLeft_end->next = pPos;
			pLeft_end = pPos;
		}
		else if (pPos->val == begin->val)
		{
			pMid_end->next = pPos;
			pMid_end = pPos;
		}
		else
		{
			pRight_end->next = pPos;
			pRight_end = pPos;
		}

		pLeft_begin = (pLeft_begin != pLeft_end) ? scLeft.next : NULL;
		pRight_begin = (pRight_begin != pRight_end) ? scRight.next : NULL;

		pPos = begin;
		if(NULL != pLeft_begin)
		{
			quitSortList(pLeft_begin, pLeft_end);
			pLeft_end->next = begin;
			end = pMid_end;
			pPos = pLeft_begin;
		}

		if(NULL != pRight_begin)
		{
			quitSortList(pRight_begin, pRight_end);
			pMid_end->next = pRight_begin;
			end = pRight_end;
		}

		begin = pPos;
	}
	
	ListNode *sortList(ListNode *head) {
		if( (NULL == head) || (NULL == head->next) )
		{
			return head;
		}
		ListNode *pPos = head->next;
		ListNode left(0);
		ListNode right(0);
		ListNode *pLeft_end = &left, *pRight_end = &right, *pMid_end = head;

		while(NULL != pPos)
		{
			if(pPos->val < head->val)
			{
				pLeft_end->next = pPos;
				pLeft_end = pPos;
			}
			else if (pPos->val == head->val)
			{
				pMid_end->next = pPos;
				pMid_end = pPos;
			}
			else
			{
				pRight_end->next = pPos;
				pRight_end = pPos;
			}
			pPos = pPos->next;
		}

		if(pLeft_end != &left)
		{
			quitSortList(left.next, pLeft_end);
			pPos = left.next;
			pLeft_end->next = head;
		}
		else
		{
			pPos = head;
		}

		if(pRight_end != &right)
		{
			quitSortList(right.next, pRight_end);
			pRight_end->next = NULL;
		}

		pMid_end->next = right.next;

		return pPos;
	}
};
