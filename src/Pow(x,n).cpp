// Source : https://leetcode.com/problems/powx-n/
// Author : zheng yi xiong 
// Date   : 2015-09-12

/********************************************************************************** 
* 
* Implement pow(x, n).
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>

using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		if (0 == n)
		{
			return 1;
		}

		bool bNegtive = false;
		if (0 > n)
		{
			n = -n;
			bNegtive = true;
		}

		double ret = 1;
		double temp = x;
		while (0 < n)
		{
			if (1 == n % 2)
			{
				ret = temp * ret;
			}
			n = n / 2;
			temp *= temp;
		}

		return bNegtive ? 1 / ret : ret;
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	double x = 2;
	int n = 7;
	Solution so;
	double ret = so.myPow(x, n);
	printf("%f pow %d is %f\n", x, n, ret);
	system("pause");
	return 0;
}

