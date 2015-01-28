// Source : https://oj.leetcode.com/problems/set-matrix-zeroes/
// Author : zheng yi xiong 
// Date   : 2015-01-23

/********************************************************************************** 
* 
* Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

* click to show follow up.

* Follow up:
* Did you use extra space?
* A straight forward solution using O(mn) space is probably a bad idea.
* A simple improvement uses O(m + n) space, but still not the best solution.
* Could you devise a constant space solution?
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		if (matrix.empty() || matrix[0].empty())
		{
			return;
		}
		
		int row_sum = matrix.size();
		int col_sum = matrix[0].size();
		vector<int> vec_zero_col(col_sum, -1);
		bool bRow_zero = false;
		for (int row = 0; row < row_sum; ++row)
		{
			bRow_zero = false;
			for (int col = 0; col < col_sum; ++col)
			{
				if (0 == matrix[row][col])
				{
					if (0 > vec_zero_col[col])
					{
						vec_zero_col[col] = row;
					}

					bRow_zero = true;
				}
				else if (!bRow_zero && (0 <= vec_zero_col[col]))
				{
					matrix[row][col] = 0;
				}
			}

			if (bRow_zero)
			{
				fill(&matrix[row][0], &matrix[row][0] + col_sum, 0);
			}
		}

		for (int col = 0; col < col_sum; ++col)
		{
			for (int row = 0; row < vec_zero_col[col]; ++row)
			{
				matrix[row][col] = 0;
			}
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int A[] = {0,0,0,5,
			   4,3,1,4,
			   0,1,1,4,
			   1,2,1,3,
			   0,0,1,1};
	Solution so;
	vector<vector<int> > matrix(5);
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			matrix[i].push_back(A[i * 4 + j]);
		}
	}
	so.setZeroes(matrix);

	return 0;
}

