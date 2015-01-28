// Source : https://oj.leetcode.com/problems/search-a-2d-matrix/
// Author : zheng yi xiong 
// Date   : 2015-01-23

/********************************************************************************** 
* 
* Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

* Integers in each row are sorted from left to right.
* The first integer of each row is greater than the last integer of the previous row.
* For example,

* Consider the following matrix:

* [
*   [1,   3,  5,  7],
*   [10, 11, 16, 20],
*   [23, 30, 34, 50]
* ]
* Given target = 3, return true.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		if (matrix.empty() || matrix[0].empty())
		{
			return false;
		}

		int row_end = matrix.size();
		int col_end = matrix[0].size();
		int row_begin = 0, col_begin = 0, row_mid = 0, col_mid = 0;
		while (row_begin < row_end)
		{
			row_mid = (row_begin + row_end) / 2;
			if (target == matrix[row_mid][col_end - 1])
			{
				return true;
			}
			else if (target < matrix[row_mid][col_end - 1])
			{
				if (target == matrix[row_mid][0])
				{
					return true;
				}
				else if (target > matrix[row_mid][0])
				{
					while (col_begin < col_end)
					{
						col_mid = (col_begin + col_end) / 2;
						if (target == matrix[row_mid][col_mid])
						{
							return true;
						}
						else if (target > matrix[row_mid][col_mid])
						{
							col_begin = col_mid + 1;
						}
						else
						{
							col_end = col_mid;
						}
					}
					break;
				}
				else
				{
					row_end = row_mid;
				}
			}
			else
			{
				row_begin = row_mid + 1;
			}
		}

		return false;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int testInt[] = { 1,  3,  5,  7,
					 10, 11, 16, 20,
					 23, 30, 34, 50};
	Solution so;
	vector<vector<int> > matrix(3);
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			matrix[i].push_back(testInt[i * 4 + j]);
		}
	}
	bool bFind = so.searchMatrix(matrix, 3);
	return 0;
}

