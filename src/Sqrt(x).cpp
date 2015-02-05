// Source : https://oj.leetcode.com/problems/sqrtx/
// Author : zheng yi xiong 
// Date   : 2015-01-31

/********************************************************************************** 
* 
* Implement int sqrt(int x).

* Compute and return the square root of x.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>

using namespace std;

class Solution {
public:
	int sqrt(int x) {
		//return sqrt1(x);
		return sqrt2(x);
	}

	int sqrt2(int x)
	{
		if (x < 2)
		{
			return x;
		}

		int low = 1, hight = x / 2;
		int mid = 0, mid2 = 0, last_mid = 1;
		while (low <= hight) 
		{
			mid = (low + hight) / 2;
			mid2 = x / mid;
			if (mid2 == mid)
			{
				return mid;
			}
			else if (mid2 < mid)
			{
				hight = mid - 1;
			}
			else
			{
				low = mid + 1;
				last_mid = mid;
			}
		}

		return last_mid;
	}
	
	//magical solution but not preciseness
	float sqrt1(float x)
	{
		float xhalf = 0.5f*x;
		int i = *(int*)&x;			// get bits for floating VALUE 
		i = 0x5f375a86- (i>>1);		// gives initial guess y0
		x = *(float*)&i;			// convert bits BACK to float
		x = x*(1.5f-xhalf*x*x);		// Newton step, repeating increases accuracy
		x = x*(1.5f-xhalf*x*x);		// Newton step, repeating increases accuracy
		x = x*(1.5f-xhalf*x*x);		// Newton step, repeating increases accuracy
		return 1/x;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution so;
	int sqrtNum = so.sqrt(5);
	return 0;
}

