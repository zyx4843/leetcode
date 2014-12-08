// Source : https://oj.leetcode.com/problems/palindrome-partitioning-ii/
// Author : zheng yi xiong 
// Date   : 2014-12-08

/********************************************************************************** 
* 
* Given a string s, partition s such that every substring of the partition is a palindrome.

* Return the minimum cuts needed for a palindrome partitioning of s.

* For example, given s = "aab",
* Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*               
**********************************************************************************/
#include "stdafx.h"
#include <vector>

using namespace std;

class CPalindrome_Partitioning_II{
public:
	int minCut(string s) {
		if (s.empty() || 1 == s.size())
		{
			return 0;
		}

		int str_len = s.length();
		int *pVec_node = new int[(str_len - 1) * str_len + 1];
		memset(pVec_node, 0, sizeof(int) * ((str_len - 1) * str_len + 1));
		int *pMin_cut = new int[str_len + 1];
		memset(pMin_cut, 0, sizeof(int) * (str_len + 1));
		pMin_cut[str_len] = -1;
		int i = str_len - 2;
		int now_pos = i * str_len;
		int prev_pos = now_pos;
		if (s[i] == s[i + 1])
		{
			pVec_node[now_pos] = i + 1;
		}
		else
		{
			pMin_cut[i] = 1;
		}

		--i;
		for (; i >= 0; --i)
		{
			now_pos = i * str_len;
			prev_pos = now_pos + str_len;
			pMin_cut[i] = pMin_cut[i + 1] + 1;
			if (s[i] == s[i + 1])
			{
				pVec_node[now_pos ++] = i + 1;
				if (pMin_cut[i] > pMin_cut[i + 2] + 1)
				{
					pMin_cut[i] = pMin_cut[i + 2] + 1;
				}
			}

			if (s[i] == s[i + 2])
			{
				pVec_node[now_pos ++] = i + 2;
				if (pMin_cut[i] > pMin_cut[i + 3] + 1)
				{
					pMin_cut[i] = pMin_cut[i + 3] + 1;
				}
			}

			while (0 != pVec_node[prev_pos])
			{
				if (pVec_node[prev_pos] < str_len - 1)
				{
					if (s[i] == s[pVec_node[prev_pos] + 1])
					{
						pVec_node[now_pos ++] = pVec_node[prev_pos] + 1;
						if (pMin_cut[i] > pMin_cut[pVec_node[prev_pos] + 2] + 1)
						{
							pMin_cut[i] = pMin_cut[pVec_node[prev_pos] + 2] + 1;
						}
					}
				}

				++prev_pos;
			}
		}

		int min_cut = pMin_cut[0];
		delete []pVec_node;
		delete []pMin_cut;

		return min_cut;
	}
};