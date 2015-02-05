// Source : https://oj.leetcode.com/problems/unique-paths-ii/
// Author : zheng yi xiong 
// Date   : 2015-02-05

/********************************************************************************** 
* 
* Follow up for "Unique Paths":

* Now consider if some obstacles are added to the grids. How many unique paths would there be?

* An obstacle and empty space is marked as 1 and 0 respectively in the grid.

* For example,
* There is one obstacle in the middle of a 3x3 grid as illustrated below.

* [
*  [0,0,0],
*  [0,1,0],
*  [0,0,0]
* ]
* The total number of unique paths is 2.

* Note: m and n will be at most 100.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		if (obstacleGrid.empty() || obstacleGrid[0].empty())
		{
			return 0;
		}

		int row_sum = obstacleGrid.size();
		int col_sum = obstacleGrid[0].size();
		vector<vector<int>> path_map(row_sum, vector<int>(col_sum, 0));

		if (0 == obstacleGrid[0][0])
		{
			path_map[0][0] = 1;
		}

		for (int row = 1; row < row_sum; ++row)
		{
			if (0 == obstacleGrid[row][0])
			{
				path_map[row][0] = path_map[row - 1][0];
			}
		}

		for (int col = 1; col < col_sum; ++col)
		{
			if (0 == obstacleGrid[0][col])
			{
				path_map[0][col] = path_map[0][col - 1];
			}
		}

		for (int row = 1; row < row_sum; ++row)
		{
			for (int col = 1; col < col_sum; ++col)
			{
				if (0 == obstacleGrid[row][col])
				{
					path_map[row][col] = path_map[row - 1][col] + path_map[row][col - 1];
				}
				else
				{
					path_map[row][col] = 0;
				}
			}
		}

		return path_map[row_sum - 1][col_sum - 1];
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int> > obstacleGrid(3, vector<int>(3, 0));
	obstacleGrid[1][1] = 1;
	Solution so;
	int paths = so.uniquePathsWithObstacles(obstacleGrid);
	return 0;
}

