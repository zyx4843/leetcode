// Source : https://oj.leetcode.com/problems/distinct-subsequences/
// Author : zheng yi xiong 
// Date   : 2014-12-17

/********************************************************************************** 
* 
* Given a string S and a string T, count the number of distinct subsequences of T in S.

* A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

* Here is an example:
* S = "rabbbit", T = "rabbit"

* Return 3.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numDistinct(string S, string T) {
		vector<int> f(T.size() + 1);
		f[0] = 1;
		for (int i = 0; i < S.size(); ++i)
		{
			//f(i,j) = (T(j) == S[i]) ? f(i - 1, j) + f(i - 1, j - 1) : f(i - 1, j)
			for (int j = T.size() - 1; j >= 0; --j)
			{
				if (T[j] == S[i])
				{
					f[j + 1] = f[j + 1] + f[j];
				}
			}
		}
		return f[T.size()];
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	string s = "rabbbit";
	string t = "rabbit";
	Solution so;
	int num = so.numDistinct(s, t);
	return 0;
}

