// Source : https://oj.leetcode.com/problems/longest-consecutive-sequence/
// Author : zheng yi xiong 
// Date   : 2014-12-11

/********************************************************************************** 
* 
* Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

* For example,
* Given [100, 4, 200, 1, 3, 2],
* The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

* Your algorithm should run in O(n) complexity.
*               
**********************************************************************************/
#include "stdafx.h"
#include <hash_set>

using namespace std;

class CLongest_Consecutive_Sequence {
public:
	int longestConsecutive(vector<int> &num) {
		int len = num.size();
		if ((0 == len) || (1 == len))
		{
			return len;
		}
		unordered_set<int> sequence_set;
		for (int i = 0; i < len; ++i)
		{
			sequence_set.insert(num[i]);
		}

		int max_num = 1;
		int temp_num = 1;
		int prev_value = 0;
		int next_value = 0;
		unordered_set<int>::iterator it;
		while (!sequence_set.empty())
		{
			it = sequence_set.begin();
			temp_num = 1;
			prev_value = *it;
			next_value = *it;
			sequence_set.erase(it);
			while (sequence_set.end() != (it = sequence_set.find(++next_value)))
			{
				sequence_set.erase(it);
				++temp_num;
			}

			while (sequence_set.end() != (it = sequence_set.find(--prev_value)))
			{
				sequence_set.erase(it);
				++temp_num;
			}

			if (temp_num > max_num)
			{
				max_num = temp_num;
			}
		}

		return max_num;
	}
};