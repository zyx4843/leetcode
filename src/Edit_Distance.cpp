// Source : https://oj.leetcode.com/problems/edit-distance/
// Author : zheng yi xiong 
// Date   : 2015-01-23

/********************************************************************************** 
* 
* Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

* You have the following 3 operations permitted on a word:

* a) Insert a character
* b) Delete a character
* c) Replace a character
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int len1 = word1.length();
		int len2 = word2.length();
		if (0 == len1)
		{
			if (0 == len2)
			{
				return 0;
			}
			else
			{
				return len2;
			}
		}
		else if (0 == len2)
		{
			return len1;
		}

		vector<vector<int>> vec_min(len2, vector<int>(len1, 0));
		if (word1[0] != word2[0])
		{
			vec_min[0][0] = 1;
		}

		for (int i = 1; i < len1; ++i)
		{
			if (word1[i] != word2[0])
			{
				vec_min[0][i] = vec_min[0][i - 1] + 1;
			}
			else
			{
				vec_min[0][i] = i;
			}
		}

		for (int i = 1; i < len2; ++i)
		{
			if (word1[0] == word2[i])
			{
				vec_min[i][0] = i;
			}
			else
			{
				vec_min[i][0] = vec_min[i - 1][0] + 1;
			}
		}

		for (int i = 1; i < len2; ++i)
		{
			for (int j = 1; j < len1; ++j)
			{
				if (word2[i] == word1[j])
				{
					vec_min[i][j] = vec_min[i - 1][j - 1];
				}
				else
				{
					vec_min[i][j] = vec_min[i - 1][j] + 1;
					if (vec_min[i][j] > vec_min[i - 1][j - 1] + 1)
					{
						vec_min[i][j] = vec_min[i - 1][j - 1] + 1;
					}

					if (vec_min[i][j] > vec_min[i][j - 1] + 1)
					{
						vec_min[i][j] = vec_min[i][j - 1] + 1;
					}
				}
			}
		}

		return vec_min[len2 - 1][len1 - 1];
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	string s1 = "sea";
	string s2 = "eta";
	Solution so;
	int mini = so.minDistance(s1, s2);
	return 0;
}

