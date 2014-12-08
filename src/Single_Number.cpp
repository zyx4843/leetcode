// Source : https://oj.leetcode.com/problems/word-break/
// Author : zheng yi xiong 
// Date   : 2014-21-03

/********************************************************************************** 
* 
* Given an array of integers, every element appears twice times except for one. Find that single one.

* Note:
* Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*               
**********************************************************************************/
#include "stdafx.h"

class CSingle_Number {
public:
	int singleNumber(int A[], int n) {
		if (0 == n)
		{
			return 0;
		}
		int single = A[0];
		for (int i = 1; i < n; ++i)
		{
			single = single ^ A[i];
		}

		return single;
	}
};