// Source : https://oj.leetcode.com/problems/jump-game/
// Author : zheng yi xiong 
// Date   : 2015-02-13

/********************************************************************************** 
* 
* Given an array of non-negative integers, you are initially positioned at the first index of the array.

* Each element in the array represents your maximum jump length at that position.

* Determine if you are able to reach the last index.

* For example:
* A = [2,3,1,1,4], return true.

* A = [3,2,1,0,4], return false.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool canJump(int A[], int n) {
		if (1 >= n)
		{
			return true;
		}

		int min_step = 1;
		for (int i = n - 2; i > 0; --i)
		{
			if (min_step > A[i])
			{
				++min_step;
			}
			else
			{
				min_step = 1;
			}
		}

		if (A[0] >= min_step)
		{
			return true;
		}
		
		return false;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int A[] = {2,3,1,1,4};
	Solution so;
	bool bCan = so.canJump(A, 5);
	return 0;
}

