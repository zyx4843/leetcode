// Source : https://oj.leetcode.com/problems/reorder-list/
// Author : zheng yi xiong 
// Date   : 2014-11-22

/********************************************************************************** 
* 
* Given a singly linked list L: L0��L1������Ln-1��Ln,
* reorder it to: L0��Ln��L1��Ln-1��L2��Ln-2����

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
      if ( (NULL == head) || (NULL == head->next) )
		{
			return;
		}
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
};