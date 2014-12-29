// Source : https://oj.leetcode.com/problems/interleaving-string/
// Author : zheng yi xiong 
// Date   : 2014-12-26

/********************************************************************************** 
* 
* Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

* For example,
* Given:
*   s1 = "aabcc",
*   s2 = "dbbca",

* When s3 = "aadbbcbcac", return true.
* When s3 = "aadbbbaccc", return false.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int s1_len = s1.length();
		int s2_len = s2.length();
		int s3_len = s3.length();
		if (s1_len + s2_len != s3_len)
		{
			return false;
		}

		vector<vector<bool> > used_route(s1_len + 1, vector<bool>(s2_len + 1, 0));
		used_route[0][0] = true;
		for (int s1_pos = 1; s1_pos <= s1_len; ++s1_pos)
		{
			if (s1[s1_pos - 1] == s3[s1_pos - 1])
			{
				used_route[s1_pos][0] = true;
			}
		}

		for (int s2_pos = 1; s2_pos <= s2_len; ++s2_pos)
		{
			if (s2[s2_pos - 1] == s3[s2_pos - 1])
			{
				used_route[0][s2_pos] = true;
			}
		}

		for (int s1_pos = 1; s1_pos <= s1_len; ++s1_pos)
		{
			for (int s2_pos = 1; s2_pos <= s2_len; ++s2_pos)
			{
				if ( (used_route[s1_pos - 1][s2_pos] && s1[s1_pos - 1] == s3[s1_pos + s2_pos - 1]) ||
					(used_route[s1_pos][s2_pos - 1] && s2[s2_pos - 1] == s3[s1_pos + s2_pos - 1]) )
				{
					used_route[s1_pos][s2_pos] = true;
				}
			}
		}

		return used_route[s1_len][s2_len];
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	string s1 = "aabaac";
	string s2 = "aadaaeaaf";
	string s3 = "aadaaeaabaafaac";/*"aadbbbaccc"*/;
	Solution so;
	bool bIn = so.isInterleave(s1, s2, s3);
	return 0;
}

