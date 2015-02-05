// Source : https://oj.leetcode.com/problems/minimum-path-sum/
// Author : zheng yi xiong 
// Date   : 2015-02-05

/********************************************************************************** 
* 
* Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

* Note: You can only move either down or right at any point in time.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		if (grid.empty() || grid[0].empty())
		{
			return 0;
		}

		int row_sum = grid.size();
		int col_sum = grid[0].size();
		vector<vector<int> > min_path_grid = grid;

		for (int row = 1; row < row_sum; ++row)
		{
			min_path_grid[row][0] = min_path_grid[row - 1][0] + grid[row][0];
		}

		for (int col = 1; col < col_sum; ++col)
		{
			min_path_grid[0][col] = min_path_grid[0][col - 1] + grid[0][col];
		}

		for (int row = 1; row < row_sum; ++row)
		{
			for (int col = 1; col < col_sum; ++col)
			{
				min_path_grid[row][col] = (min_path_grid[row - 1][col] < min_path_grid[row][col - 1]) ? min_path_grid[row - 1][col] : min_path_grid[row][col - 1];
				min_path_grid[row][col] += grid[row][col];
			}
		}

		return min_path_grid[row_sum - 1][col_sum - 1];
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

