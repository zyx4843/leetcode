// Source : https://oj.leetcode.com/problems/copy-list-with-random-pointer/
// Author : zheng yi xiong 
// Date   : 2014-12-01

/********************************************************************************** 
* 
* A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

* Return a deep copy of the list.
*               
**********************************************************************************/
#include "stdafx.h"
#include <map>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class CCopy_List_with_Random_Pointer {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (NULL == head)
		{
			return NULL;
		}
		map<RandomListNode *, RandomListNode *> map_randomlist;

		RandomListNode *pCopyHead = new RandomListNode(head->label);
		map_randomlist.insert(map<RandomListNode *, RandomListNode *>::value_type(head, pCopyHead));
		RandomListNode *pSrcNode = head->next;
		RandomListNode *pDetNode = pCopyHead;
		while (NULL != pSrcNode)
		{
			pDetNode->next = new RandomListNode(pSrcNode->label);
			map_randomlist.insert(map<RandomListNode *, RandomListNode *>::value_type(pSrcNode, pDetNode->next));
			pSrcNode = pSrcNode->next;
			pDetNode = pDetNode->next;
		}

		pSrcNode = head;
		pDetNode = pCopyHead;
		while (NULL != pSrcNode)
		{
			if (NULL != pSrcNode->random)
			{
				pDetNode->random = map_randomlist[pSrcNode->random];
			}
			pSrcNode = pSrcNode->next;
			pDetNode = pDetNode->next;
		}

		return pCopyHead;
	}
};