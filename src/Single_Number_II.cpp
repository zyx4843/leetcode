// Source : https://oj.leetcode.com/problems/word-break-ii/
// Author : zheng yi xiong 
// Date   : 2014-21-02

/********************************************************************************** 
* 
* Given an array of integers, every element appears three times except for one. Find that single one.

* Note:
* Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*               
**********************************************************************************/
#include "stdafx.h"

class CSingle_Number_II {
public:
	int singleNumber(int A[], int n) {
		int odd	= 0;		//三次中出现奇数次的数位
		int even = 0;		//三次中出现偶数次的数位
		int temp = 0;		//消除出现三次的数位
		for (int i = 0; i < n; ++i)
		{
			even ^= odd & A[i];
			odd ^= A[i];
			temp = ~(odd & even);
			even &= temp;
			odd &= temp;
		}

		return odd;
	}
};