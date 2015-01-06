// Source : https://oj.leetcode.com/problems/scramble-string/
// Author : zheng yi xiong 
// Date   : 2015-01-06

/********************************************************************************** 
* 
* Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

* Below is one possible representation of s1 = "great":

*      great
*     /    \
*    gr    eat
*   / \    /  \
*  g   r  e   at
*             / \
*            a   t
* To scramble the string, we may choose any non-leaf node and swap its two children.

* For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

*       rgeat
*      /    \
*     rg    eat
*    / \    /  \
*   r   g  e   at
*              / \
*             a   t
* We say that "rgeat" is a scrambled string of "great".

* Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

*       rgtae
*      /    \
*     rg    tae
*    / \    /  \
*   r   g  ta  e
*         / \
*        t   a
* We say that "rgtae" is a scrambled string of "great".

* Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1.size() != s2.size())
		{
			return false;
		}

		if (s1.empty())
		{
			return false;
		}

		int len = s1.size();
		vector<vector<vector<bool>>> bScramble(len + 1, vector<vector<bool>>(len, vector<bool>(len, false)));
		for (int i = 0; i < len; ++i)
		{
			for (int j = 0; j < len; ++j)
			{
				if (s1[i] == s2[j])
				{
					bScramble[1][i][j] = true;
				}
			}
		}

		for (int n = 2; n <= len; ++n)
		{
			for (int i = 0; i + n <= len; ++i)
			{
				for (int j = 0; j + n <= len; ++j)
				{
					for (int k = 1; k < n; ++k)
					{
						if ( (bScramble[k][i][j] && bScramble[n - k][i + k][j + k]) || (bScramble[k][i][j + n - k] && bScramble[n - k][i + k][j]) )
						{
							bScramble[n][i][j] = true;
							break;
						}
					}
				}
			}
		}

		return bScramble[len][0][0];
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	string s1 = "abcd";
	string s2 = /*"dbca";*/"bdac";
	Solution so;
	bool bScramble = so.isScramble(s1, s2);
	return 0;
}

