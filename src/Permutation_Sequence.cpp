// Source : https://oj.leetcode.com/problems/permutation-sequence/
// Author : zheng yi xiong 
// Date   : 2015-02-09

/********************************************************************************** 
* 
* The set [1,2,3,бн,n] contains a total of n! unique permutations.

* By listing and labeling all of the permutations in order,
* We get the following sequence (ie, for n = 3):

* "123"
* "132"
* "213"
* "231"
* "312"
* "321"
* Given n and k, return the k th permutation sequence.

* Note: Given n will be between 1 and 9 inclusive.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		vector<char> num(n);
		int sumSequence = 1;
		for (int i = 0; i < n; ++i)
		{
			num[i] = '0' + i + 1;
			sumSequence *= (i + 1);
		}

		if (k > sumSequence)
		{
			return "";
		}

		string s(n, '0');
		int s_pos = 0;
		sumSequence /= (n - s_pos);
		int cur_pos = (k - 1) / sumSequence;
		k = (k - 1) % sumSequence;
		s[s_pos] = num[cur_pos];
		num.erase(num.begin() + cur_pos);
		for (s_pos = 1; s_pos < n; ++s_pos)
		{
			sumSequence /= (n - s_pos);
			cur_pos = k / sumSequence;
			k = k% sumSequence;
			s[s_pos] = num[cur_pos];
			num.erase(num.begin() + cur_pos);
		}

		return s;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution so;
	string str = so.getPermutation(3, 4);
	return 0;
}

