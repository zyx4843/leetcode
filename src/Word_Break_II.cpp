// Source : https://oj.leetcode.com/problems/word-break-ii/
// Author : zheng yi xiong 
// Date   : 2014-11-29

/********************************************************************************** 
* 
* Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

* Return all such possible sentences.

* For example, given
* s = "catsanddog",
* dict = ["cat", "cats", "and", "sand", "dog"].

* A solution is ["cats and dog", "cat sand dog"].
*               
**********************************************************************************/
#include "stdafx.h"
#include <string>
#include <vector>

using namespace std;

class CWord_Break_II {
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		if (s.empty())
		{
			vector<string> vec_str;
			return vec_str;
		}

		vector<int> vec_end_pos;
		int len = s.size();
		int end_pos = len - 1;
		vector<vector<string>> vec_start_str(len);
		bool bAdd = false;
		int vec_len = 0;
		for (; end_pos > 0; --end_pos)
		{
			bAdd = false;
			vec_len = vec_end_pos.size();
			string sub_str1 = s.substr(end_pos, len - end_pos);
			if (dict.find(sub_str1) != dict.end())
			{
				vec_start_str[vec_len].push_back(sub_str1);
				bAdd = true;
			}

			for (int i = 0; i < vec_end_pos.size(); ++i)
			{
				string sub_str2 = s.substr(end_pos, vec_end_pos[i] - end_pos);
				if (dict.find(sub_str2) != dict.end())
				{
					for (int j = 0; j < vec_start_str[i].size(); ++j)
					{
						vec_start_str[vec_len].push_back(sub_str2 + " " + vec_start_str[i][j]);
					}
					bAdd = true;
				}
			}

			if (bAdd)
			{
				vec_end_pos.push_back(end_pos);
			}
		}

		vec_len = vec_end_pos.size();
		string sub_str1 = s.substr(0, len);
		if (dict.find(sub_str1) != dict.end())
		{
			vec_start_str[vec_len].push_back(sub_str1);
		}

		for (int i = 0; i < vec_end_pos.size(); ++i)
		{
			string sub_str2 = s.substr(0, vec_end_pos[i]);
			if (dict.find(sub_str2) != dict.end())
			{
				for (int j = 0; j < vec_start_str[i].size(); ++j)
				{
					vec_start_str[vec_len].push_back(sub_str2 + " " + vec_start_str[i][j]);
				}
			}
		}

		return vec_start_str[vec_len];
	}
};