// Source : https://oj.leetcode.com/problems/spiral-matrix/
// Author : zheng yi xiong 
// Date   : 2015-02-14

/********************************************************************************** 
* 
* Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

* For example,
* Given the following matrix:

* [
*  [ 1, 2, 3 ],
*  [ 4, 5, 6 ],
*  [ 7, 8, 9 ]
* ]
* You should return [1,2,3,6,9,8,7,4,5].
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		if (matrix.empty() || matrix[0].empty())
		{
			vector<int> ret;
			return ret;
		}

		enum
		{
			GO_LEFT,
			GO_RIGHT,
			GO_TOP,
			GO_BOTTOM
		};

		vector<int> ret;
		int top = 1, bottom = matrix.size(), left = 0, right = matrix[0].size();
		int row = 0, col = 0;
		int goDirect = GO_RIGHT;
		while (true)
		{
			ret.push_back(matrix[row][col]);
			if (GO_RIGHT == goDirect)
			{
				if (col + 1 < right)
				{
					++col;
				}
				else
				{
					--right;
					if (row + 1 < bottom)
					{
						goDirect = GO_BOTTOM;
						++row;
					}
					else
					{
						break;
					}
				}
			}
			else if (GO_BOTTOM == goDirect)
			{
				if (row + 1 < bottom)
				{
					++row;
				}
				else
				{
					--bottom;
					if (col - 1 >= left)
					{
						goDirect = GO_LEFT;
						--col;
					}
					else
					{
						break;
					}
				}
			}
			else if (GO_LEFT == goDirect)
			{
				if (col - 1 >= left)
				{
					--col;
				}
				else
				{
					++left;
					if (row - 1 >= top)
					{
						goDirect = GO_TOP;
						--row;
					}
					else
					{
						break;
					}
				}
			}
			else if (GO_TOP == goDirect)
			{
				if (row - 1 >= top)
				{
					--row;
				}
				else
				{
					++top;
					if (col + 1 < right)
					{
						goDirect = GO_RIGHT;
						++col;
					}
					else
					{
						break;
					}
				}
			}
		}

		return ret;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	/*Solution so;
	vector<int> ret = so.spiralOrder(so.generateMatrix(3));*/
	return 0;
}

