// Source : https://oj.leetcode.com/problems/combinations/
// Author : zheng yi xiong 
// Date   : 2015-01-14

/********************************************************************************** 
* 
* Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

* For example,
* If n = 4 and k = 2, a solution is:

* [
*  [2,4],
*  [3,4],
*  [2,3],
*  [1,2],
*  [1,3],
*  [1,4],
* ]
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > vec_ret;
		if (0 >= n)
		{
			return vec_ret;
		}
		else if (n == k)
		{
			vector<int> temp;
			for (int i = 1; i <= n; ++i)
			{
				temp.push_back(i);
			}
			vec_ret.push_back(temp);
			return vec_ret;
		}
		else if (1 == k)
		{
			for (int i = 1; i <= n; ++i)
			{
				vector<int> temp;
				temp.push_back(i);
				vec_ret.push_back(temp);
			}
			return vec_ret;
		}

		for (int i = n; i >= k; --i)
		{
			vector<vector<int> > vec_temp = combine(i - 1, k - 1);
			for (int j = 0; j < vec_temp.size(); ++j)
			{
				vec_temp[j].push_back(i);
				vec_ret.push_back(vec_temp[j]);
			}
		}

		return vec_ret;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution so;
	vector<vector<int> > vec_ret = so.combine(4, 2);
	return 0;
}

