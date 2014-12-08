// Source : https://oj.leetcode.com/problems/word-break/
// Author : zheng yi xiong 
// Date   : 2014-11-30

/********************************************************************************** 
* 
* Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

* For example, given
* s = "leetcode",
* dict = ["leet", "code"].

* Return true because "leetcode" can be segmented as "leet code".
*               
**********************************************************************************/

#include "stdafx.h"
#include <string>
#include <vector>

using namespace std;

class CWord_Break {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		if (s.empty())
		{
			return false;
		}

		vector<int> vec_end_pos;
		int len = s.size();
		int end_pos = 1;
		vec_end_pos.push_back(0);
		for (; end_pos <= len; ++end_pos)
		{
			for (vector<int>::reverse_iterator it = vec_end_pos.rbegin(); it != vec_end_pos.rend(); ++it)
			{
				string sub_str = s.substr((*it), end_pos - (*it));
				if (dict.find(sub_str) != dict.end())
				{
					vec_end_pos.push_back(end_pos);
					break;
				}
			}
		}

		if (len == vec_end_pos.back())
		{
			return true;
		}

		return false;
	}
};