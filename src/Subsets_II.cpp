// Source : https://oj.leetcode.com/problems/subsets-ii/
// Author : zheng yi xiong 
// Date   : 2014-12-31

/********************************************************************************** 
* 
* Given a collection of integers that might contain duplicates, S, return all possible subsets.

* Note:
*  Elements in a subset must be in non-descending order.
*  The solution set must not contain duplicate subsets.
* For example,
*  If S = [1,2,2], a solution is:

* [
*   [2],
*   [1],
*   [1,2,2],
*   [2,2],
*   [1,2],
*   []
* ]
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		sort(S.begin(), S.end());
		vector<vector<int> > vec_vec_int;
		vector<int> temp_vec;
		vec_vec_int.push_back(temp_vec);
		int index = 0;
		SubVecDup(vec_vec_int, S, index);

		return vec_vec_int;
	}
private:
	void SubVecDup(vector<vector<int> > &vec_vec_int, vector<int> &S, int &index)
	{
		int vec_vec_len = vec_vec_int.size();
		int vec_vec_index = 0;
		for (int i = index; i < S.size() - 1; ++i)
		{
			for (int j = 0; j < vec_vec_len; ++j)
			{
				vector<int> temp_vec(vec_vec_int[vec_vec_index + j]);
				temp_vec.push_back(S[i]);
				vec_vec_int.push_back(temp_vec);
			}

			if (S[i + 1] != S[i])
			{
				index = i + 1;
				SubVecDup(vec_vec_int, S, index);
				return;
			}

			vec_vec_index += vec_vec_len;
		}

		for (int j = 0; j < vec_vec_len; ++j)
		{
			vector<int> temp_vec(vec_vec_int[vec_vec_index + j]);
			temp_vec.push_back(S.back());
			vec_vec_int.push_back(temp_vec);
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> S;
	S.push_back(1);
	S.push_back(2);
	S.push_back(2);
	Solution so;
	vector<vector<int> > vec_vec_int = so.subsetsWithDup(S);
	return 0;
}

