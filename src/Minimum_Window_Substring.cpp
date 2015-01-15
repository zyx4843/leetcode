// Source : https://oj.leetcode.com/problems/minimum-window-substring/
// Author : zheng yi xiong 
// Date   : 2015-01-15

/********************************************************************************** 
* 
* Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

* For example,
* S = "ADOBECODEBANC"
* T = "ABC"
* Minimum window is "BANC".

* Note:
* If there is no such window in S that covers all characters in T, return the emtpy string "".

* If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string minWindow(string S, string T) {
		if (T.empty() || S.empty() || T.size() > S.size())
		{
			return "";
		}

		vector<int>  vec_bInT_num(256, 0);
		vector<int>	 vec_appere_num(256, 0);
		int size_T = T.size(), size_S = S.size();
		for (int i = 0; i < size_T; ++i)
		{
			++vec_bInT_num[T[i]];
		}

		int curNum = 0, minNum = size_S + 1;
		int start = 0, min_start = 0;
		for (int i = 0; i < size_S; ++i)
		{
			if (0 != vec_bInT_num[S[i]])
			{
				++vec_appere_num[S[i]];
				if (0 == curNum)
				{
					start = i;
					if (1 == size_T)
					{
						return T;
					}
					else
					{
						++curNum;
						continue;
					}
				}

				if (vec_bInT_num[S[i]] >= vec_appere_num[S[i]])
				{
					++curNum;
					if (size_T == curNum)
					{
						if ( minNum > (i - start) )
						{
							minNum = i - start;
							min_start = start;
						}
					}
				}
				else
				{
					for (int j = start; j <= i; ++j)
					{
						if (0 != vec_bInT_num[S[j]])
						{
							if (vec_bInT_num[S[j]] >= vec_appere_num[S[j]])
							{
								start = j;
								if (size_T == curNum)
								{
									if ( minNum > (i - start) )
									{
										minNum = i - start;
										min_start = start;
									}
								}
								break;
							}
							--vec_appere_num[S[j]];
						}
					}
				}
			}
		}

		if (minNum == size_S + 1)
		{
			return "";
		}
		else
		{
			return S.substr(min_start, minNum + 1);
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution so;
	string S = "ADOBECODEBANC";
	string T = "ABC";
	string ret_str = so.minWindow(S, T);
	return 0;
}

