// Source : https://oj.leetcode.com/problems/unique-paths/
// Author : zheng yi xiong 
// Date   : 2015-02-05

/********************************************************************************** 
* 
* A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

* The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

* How many possible unique paths are there?

* Above is a 3 x 7 grid. How many possible unique paths are there?

* Note: m and n will be at most 100.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> path_map(m, vector<int>(n, 1));
		for (int row = 1; row < m; ++row)
		{
			for (int col = 1; col < n; ++col)
			{
				path_map[row][col] = path_map[row - 1][col] + path_map[row][col - 1];
			}
		}

		return path_map[m - 1][n - 1];
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution so;
	int paths = so.uniquePaths(2, 3);
	return 0;
}

