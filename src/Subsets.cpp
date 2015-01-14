// Source : https://oj.leetcode.com/problems/subsets/
// Author : zheng yi xiong 
// Date   : 2015-01-14

/********************************************************************************** 
* 
* Given a set of distinct integers, S, return all possible subsets.

* Note:
* Elements in a subset must be in non-descending order.
* The solution set must not contain duplicate subsets.
* For example,
* If S = [1,2,3], a solution is:

* [
*  [3],
*  [1],
*  [2],
*  [1,2,3],
*  [1,3],
*  [2,3],
*  [1,2],
*  []
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
	vector<vector<int> > subsets(vector<int> &S) {
		sort(S.begin(), S.end());
		vector<vector<int> > vec_vec_int;
		vector<int> temp_vec;
		vec_vec_int.push_back(temp_vec);
		for (int i = 0; i < S.size(); ++i)
		{
			int vec_vec_len = vec_vec_int.size();
			for (int j = 0; j < vec_vec_len; ++j)
			{
				vector<int> temp_vec(vec_vec_int[j]);
				temp_vec.push_back(S[i]);
				vec_vec_int.push_back(temp_vec);
			}
		}

		return vec_vec_int;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> S;
	S.push_back(1);
	S.push_back(2);
	S.push_back(3);
	Solution so;
	vector<vector<int> > vec_vec_int = so.subsets(S);
	return 0;
}

