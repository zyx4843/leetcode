// Source : https://oj.leetcode.com/problems/plus-one/
// Author : zheng yi xiong 
// Date   : 2015-02-02

/********************************************************************************** 
* 
* Given a non-negative number represented as an array of digits, plus one to the number.

* The digits are stored such that the most significant digit is at the head of the list.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		int carry = 1;
		for (vector<int>::reverse_iterator reIter = digits.rbegin(); reIter != digits.rend(); ++reIter)
		{
			*reIter += carry;
			carry = (*reIter) / 10;
			*reIter = (*reIter) % 10;
		}

		if (0 < carry)
		{
			digits.insert(digits.begin(), carry);
		}

		return digits;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> digits;
	digits.push_back(9);
	Solution so;
	so.plusOne(digits);
	return 0;
}

