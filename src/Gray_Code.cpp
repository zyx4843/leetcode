// Source : https://oj.leetcode.com/problems/gray-code/
// Author : zheng yi xiong 
// Date   : 2015-01-06

/********************************************************************************** 
* 
* The gray code is a binary numeral system where two successive values differ in only one bit.

* Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

* For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

* 00 - 0
* 01 - 1
* 11 - 3
* 10 - 2
* Note:
*  For a given n, a gray code sequence is not uniquely defined.

* For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

* For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> vec_gray;
		if (0 >= n)
		{
			vec_gray.push_back(0);
			return vec_gray;
		}

		vec_gray.push_back(0);
		vec_gray.push_back(1);
		int prev_len = 2;
		int add_value = 0;
		for (int i = 1; i < n; ++i)
		{
			add_value = 0x1 << i;
			for (int j = prev_len - 1; j >= 0; --j)
			{
				vec_gray.push_back(vec_gray[j] + add_value);
			}
			prev_len <<= 1;
		}

		return vec_gray;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 3;
	if ( argc > 1) {
		n = _wtoi(argv[1]);
	}

	Solution so;
	vector<int> vec_int = so.grayCode(n);
	return 0;
}

