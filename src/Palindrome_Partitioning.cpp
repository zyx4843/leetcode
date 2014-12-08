// Source : https://oj.leetcode.com/problems/palindrome-partitioning/
// Author : zheng yi xiong 
// Date   : 2014-12-08

/********************************************************************************** 
* 
* Given a string s, partition s such that every substring of the partition is a palindrome.

* Return all possible palindrome partitioning of s.

* For example, given s = "aab",
* Return

* [
*   ["aa","b"],
*   ["a","a","b"]
* ]
*               
**********************************************************************************/
#include "stdafx.h"
#include <vector>

using namespace std;

class CPalindrome_Partitioning{
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> vec_str;
		if (s.empty())
		{
			return vec_str;
		}

		int str_len = s.length();
		if (1 == str_len)
		{
			vector<string> str_temp;
			str_temp.push_back(s);
			vec_str.push_back(str_temp);
			return vec_str;
		}

		int *pVec_node = new int[(str_len - 1) * str_len + 1];
		memset(pVec_node, 0, sizeof(int) * ((str_len - 1) * str_len + 1));
		int i = str_len - 2;
		int now_pos = i * str_len;
		int prev_pos = now_pos;
		if (s[i] == s[i + 1])
		{
			pVec_node[now_pos] = i + 1;
		}

		--i;
		for (; i >= 0; --i)
		{
			now_pos = i * str_len;
			prev_pos = now_pos + str_len;
			if (s[i] == s[i + 1])
			{
				pVec_node[now_pos ++] = i + 1;
			}

			if (s[i] == s[i + 2])
			{
				pVec_node[now_pos ++] = i + 2;
			}

			while (0 != pVec_node[prev_pos])
			{
				if (pVec_node[prev_pos] < str_len - 1)
				{
					if (s[i] == s[pVec_node[prev_pos] + 1])
					{
						pVec_node[now_pos ++] = pVec_node[prev_pos] + 1;
					}
				}

				++prev_pos;
			}
		}

		vector<int> vec_pos;
		now_pos = 0;
		vector<string> str_temp;
		str_temp.push_back(s.substr(0, 1));
		vec_str.push_back(str_temp);
		vec_pos.push_back(1);
		while (0 != pVec_node[now_pos])
		{
			str_temp.clear();
			str_temp.push_back(s.substr(0, pVec_node[now_pos] + 1));
			vec_str.push_back(str_temp);
			vec_pos.push_back(pVec_node[now_pos] + 1);
			++now_pos;
		}

		int vec_index = 0;
		while (str_len != vec_pos[0])
		{
			for (vec_index = 0; vec_index < vec_pos.size(); ++vec_index)
			{
				if (str_len != vec_pos[vec_index])
				{
					now_pos = vec_pos[vec_index] * str_len;
					while (0 != pVec_node[now_pos])
					{
						vec_str.push_back(vec_str[vec_index]);
						vec_str.back().push_back(s.substr(vec_pos[vec_index], pVec_node[now_pos] - vec_pos[vec_index] + 1));
						vec_pos.push_back(pVec_node[now_pos] + 1);
						++now_pos;
					}
					vec_str[vec_index].push_back(s.substr(vec_pos[vec_index], 1));
					++vec_pos[vec_index];
				}
			}
		}

		delete []pVec_node;

		return vec_str;
	}
};