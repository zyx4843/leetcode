// Source : https://oj.leetcode.com/problems/spiral-matrix-ii/
// Author : zheng yi xiong 
// Date   : 2015-02-10

/********************************************************************************** 
* 
* Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

* For example,
* Given n = 3,

* You should return the following matrix:
* [
*  [ 1, 2, 3 ],
*  [ 8, 9, 4 ],
*  [ 7, 6, 5 ]
* ]
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		if (0 >= n)
		{
			vector<vector<int> > ret;
			return ret;
		}

		enum
		{
			GO_LEFT,
			GO_RIGHT,
			GO_TOP,
			GO_BOTTOM
		};

		vector<vector<int>> matrix(n, vector<int>(n, 0));
		int goDirect = GO_RIGHT;
		int row = 0, col = 0, values = 1;
		matrix[0][0] = 1;
		while (true)
		{
			if (goDirect == GO_RIGHT)
			{
				if (col + 1 < n && 0 == matrix[row][col + 1])
				{
					matrix[row][++col] = ++values;
				}
				else if (row + 1 < n && 0 == matrix[row + 1][col])
				{
					matrix[++row][col] = ++values;
					goDirect = GO_BOTTOM;
				}
				else
				{
					break;
				}
			}
			else if (goDirect == GO_BOTTOM)
			{
				if (row + 1 < n && 0 == matrix[row + 1][col])
				{
					matrix[++row][col] = ++values;
				}
				else if (col - 1 >= 0 && 0 == matrix[row][col - 1])
				{
					matrix[row][--col] = ++values;
					goDirect = GO_LEFT;
				}
				else
				{
					break;
				}
			}
			else if (goDirect == GO_LEFT)
			{
				if (col - 1 >= 0 && 0 == matrix[row][col - 1])
				{
					matrix[row][--col] = ++values;
				}
				else if (row - 1 >= 0 && 0 == matrix[row - 1][col])
				{
					matrix[--row][col] = ++values;
					goDirect = GO_TOP;
				}
				else
				{
					break;
				}
			}
			else if (goDirect == GO_TOP)
			{
				if (row - 1 >= 0 && 0 == matrix[row - 1][col])
				{
					matrix[--row][col] = ++values;
				}
				else if (col + 1 < n && 0 == matrix[row][col + 1])
				{
					matrix[row][++col] = ++values;
					goDirect = GO_RIGHT;
				}
				else
				{
					break;
				}
			}
		}

		return matrix;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution so;
	vector<vector<int> > ret = so.generateMatrix(3);
	return 0;
}

