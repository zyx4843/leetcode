// Source : https://oj.leetcode.com/problems/word-ladder-ii/
// Author : zheng yi xiong 
// Date   : 2014-12-12

/********************************************************************************** 
* 
* Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

* Only one letter can be changed at a time
* Each intermediate word must exist in the dictionary
* For example,

* Given:
* start = "hit"
* end = "cog"
* dict = ["hot","dot","dog","lot","log"]

* Return
* [
*   ["hit","hot","dot","dog","cog"],
*   ["hit","hot","lot","log","cog"]
* ]

* Note:
* All words have the same length.
* All words contain only lowercase alphabetic characters.
*               
**********************************************************************************/
#include "stdafx.h"
#include <string>
#include <map>
#include <queue>
#include <hash_set>

using namespace std;

class CWord_Ladder_II {
	typedef struct __level_node__
	{
		int level;
		list<unordered_set<string>::iterator> list_prev;
		int useNum;
		__level_node__():level(0),useNum(0){}
	}LEVEL_NODE;
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		int wordLen = start.length();
		map<string, LEVEL_NODE> map_ladder;
		LEVEL_NODE start_node;
		start_node.level = 1;
		start_node.useNum = 0;
		map_ladder.insert(map<string, LEVEL_NODE>::value_type(start, start_node));
		int parent_num = 1;
		int son_num = 0;
		int now_length = 0;
		queue<string> queue_ladder;
		queue_ladder.push(start);
		vector<vector<string>> vec_ret;
		unordered_set<string>::iterator hash_it;
		while (0 != parent_num)
		{
			string node_str = queue_ladder.front();
			queue_ladder.pop();
			now_length = map_ladder[node_str].level;
			hash_it = dict.find(node_str);
			for (int i = 0; i < wordLen; ++i)
			{
				string temp_str = node_str;
				for (char ch = 'a'; ch <= 'z'; ++ch)
				{
					temp_str[i] = ch;
					if (dict.end() != dict.find(temp_str))
					{
						if (0 == map_ladder[temp_str].level)
						{
							map_ladder[temp_str].list_prev.push_back(hash_it);
							map_ladder[temp_str].useNum = 1;
							map_ladder[temp_str].level = now_length + 1;
							queue_ladder.push(temp_str);
							++son_num;
						}
						else if (now_length + 1 == map_ladder[temp_str].level)
						{
							map_ladder[temp_str].list_prev.push_back(hash_it);
						}
					}
				}
			}

			--parent_num;
			if (0 == parent_num)
			{
				if (0 != map_ladder[end].level)
				{
					int level = map_ladder[end].level;
					vector<string> temp_vec(map_ladder[end].level);
					temp_vec[level - 1] = end;
					vec_ret.push_back(temp_vec);
					int parent_num = 1;
					while(1 < level)
					{
						--level;
						parent_num = vec_ret.size();
						for (int i = 0; i < parent_num; ++i)
						{
							string temp_str = vec_ret[i][level];
							vector<string> str_vec(vec_ret[i]);
							list<unordered_set<string>::iterator>::iterator list_it = map_ladder[temp_str].list_prev.begin();
							vec_ret[i][level - 1] = *(*list_it);
							++list_it;
							while (list_it != map_ladder[temp_str].list_prev.end())
							{
								str_vec[level - 1] = *(*list_it);
								vec_ret.push_back(str_vec);
								++list_it;
							}
						}
					}
					break;
				}
				parent_num = son_num;
				son_num = 0;
			}
		}

		return vec_ret;
	}
};