// Source : https://oj.leetcode.com/problems/reorder-list/
// Author : zheng yi xiong 
// Date   : 2014-11-22

/********************************************************************************** 
* 
* Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
* reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­

* You must do this in-place without altering the nodes' values.

* For example,
* Given {1,2,3,4}, reorder it to {1,4,2,3}.
*               
**********************************************************************************/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
      if ( (NULL == head) || (NULL == head->next) || (NULL == head->next->next) )
		{
			return;
		}
		
		reorderList_1(ListNode *head);			//run time 236ms
		//reorderList_2(ListNode *head);		//run time 280ms
    }

	void reorderList_1(ListNode *head)
	{
		ListNode *pMidNode = FindMidNode(head);
		pMidNode = ReverseList(pMidNode);

		ListNode *pPos = head, *pTemp = NULL;

		do 
		{
			pTemp = pPos->next;
			pPos->next = pMidNode;
			pMidNode = pMidNode->next;
			pPos->next->next = pTemp;
			pPos = pTemp;

		} while (NULL != pMidNode);
	}

	void reorderList_2(ListNode *head)
	{
		std::vector<ListNode *> vecNodePointer;
		ListNode *pPos = head;
		while (NULL != pPos)
		{
			vecNodePointer.push_back(pPos);
			pPos = pPos->next;
		}

		pPos = head;
		int vecSize = vecNodePointer.size();
		int vecRIndex = vecSize - 1;
		int vecMid = vecSize / 2;
		int vecIndex = 0;
		while (vecRIndex > vecMid)
		{
			vecNodePointer[vecIndex]->next = vecNodePointer[vecRIndex];
			++vecIndex;
			vecNodePointer[vecRIndex]->next = vecNodePointer[vecIndex];
			--vecRIndex;
		}
		vecNodePointer[vecRIndex]->next = NULL;
	}

	ListNode *FindMidNode(ListNode *pHead)
	{
		ListNode *p1 = pHead, *p2 = pHead;
		while ( (NULL != p2) && (NULL != p2->next))
		{
			p1 = p1->next;
			p2 = p2->next->next;
		}

		p2 = p1->next;
		p1->next = NULL;

		return p2;
	}

	ListNode *ReverseList(ListNode *pHead)
	{
		ListNode *pReverseHead = NULL, *pTemp = NULL;
		while (NULL != pHead)
		{
			pTemp = pReverseHead;
			pReverseHead = pHead;
			pHead = pHead->next;
			pReverseHead->next = pTemp;
		}

		return pReverseHead;
	}
};