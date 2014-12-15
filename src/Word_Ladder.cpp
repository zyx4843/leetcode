// Source : https://oj.leetcode.com/problems/word-ladder/
// Author : zheng yi xiong 
// Date   : 2014-12-10

/********************************************************************************** 
* 
* Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

* Only one letter can be changed at a time
* Each intermediate word must exist in the dictionary
* For example,

* Given:
* start = "hit"
* end = "cog"
* dict = ["hot","dot","dog","lot","log"]
* As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
* return its length 5.

* Note:
* Return 0 if there is no such transformation sequence.
* All words have the same length.
* All words contain only lowercase alphabetic characters.
*               
**********************************************************************************/
#include "stdafx.h"
#include <string>
#include <map>
#include <queue>

using namespace std;

class CWord_Ladder {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		int wordLen = start.length();
		map<string, int> map_ladder;
		map_ladder.insert(map<string, int>::value_type(start, 1));
		queue<string> queue_ladder;
		queue_ladder.push(start);
		int now_length = 0;
		while ( (!queue_ladder.empty()) && (0 == map_ladder[end]) )
		{
			string node_str = queue_ladder.front();
			queue_ladder.pop();
			now_length = map_ladder[node_str];
			for (int i = 0; i < wordLen; ++i)
			{
				string temp_str = node_str;
				for (char ch = 'a'; ch <= 'z'; ++ch)
				{
					temp_str[i] = ch;
					if ( (0 < dict.count(temp_str)) && (0 == map_ladder[temp_str]))
					{
						map_ladder[temp_str] = now_length + 1;
						queue_ladder.push(temp_str);
					}
				}
			}
		}

		return map_ladder[end];
	}
};