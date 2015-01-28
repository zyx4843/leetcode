// Source : https://oj.leetcode.com/problems/climbing-stairs/
// Author : zheng yi xiong 
// Date   : 2015-01-28

/********************************************************************************** 
* 
* You are climbing a stair case. It takes n steps to reach to the top.

* Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if ((1 == n) || (2 == n) || (3 == n))
		{
			return n;
		}

		int pos = 0;
		int way[2] = {1, 2};
		for (int i = 2; i < n; ++i)
		{
			if (0 == pos)
			{
				way[0] += way[1];
				pos = 1;
			}
			else
			{
				way[1] += way[0];
				pos = 0;
			}
		}

		if (0 == pos)
		{
			return way[1];
		}
		else
		{
			return way[0];
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 5;
	if ( argc > 1) {
		n = _wtoi(argv[1]);
	}

	Solution so;
	int way = so.climbStairs(n);
	return 0;
}

