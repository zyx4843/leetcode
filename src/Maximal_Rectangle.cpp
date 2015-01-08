// Source : https://oj.leetcode.com/problems/maximal-rectangle/
// Author : zheng yi xiong 
// Date   : 2015-01-06

/********************************************************************************** 
* 
* Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		if (matrix.empty() || matrix[0].empty())
		{
			return 0;
		}

		int row_sum = matrix.size();
		int col_sum = matrix[0].size();
		vector<int> col_hight(col_sum, 0);
		vector<int> hight_len(row_sum + 1, 0);
		int *pHight = new int[row_sum + 1];
		for (int row = 0; row < row_sum; ++row)
		{
			memset(pHight, 0, sizeof(int) * (row_sum + 1));
			if ('1' == matrix[row][0])
			{
				col_hight[0] += 1;
				pHight[col_hight[0]] = 1;

				for (int i = 1; i < col_hight[0]; ++i)
				{
					pHight[i] += 1;
				}
			}
			else
			{
				col_hight[0] = 0;
			}

			for (int col = 1; col < col_sum; ++col)
			{
				if ('1' == matrix[row][col])
				{
					col_hight[col] += 1;
					pHight[col_hight[col]] += 1;
					if (col_hight[col - 1] > col_hight[col])
					{
						for (int i = col_hight[col] + 1; i <= col_hight[col - 1]; ++i)
						{
							if (hight_len[i] < pHight[i])
							{
								hight_len[i] = pHight[i];
							}
							pHight[i] = 0;
						}
					}

					for (int i = 1; i < col_hight[col]; ++i)
					{
						pHight[i] += 1;
					}
				}
				else
				{
					col_hight[col] = 0;

					for (int i = 1; i <= row + 1; ++i)
					{
						if (hight_len[i] < pHight[i])
						{
							hight_len[i] = pHight[i];
						}
					}

					memset(pHight, 0, sizeof(int) * (row_sum + 1));
				}
			}

			for (int i = 1; i <= col_hight[col_sum - 1]; ++i)
			{
				if (hight_len[i] < pHight[i])
				{
					hight_len[i] = pHight[i];
				}
			}
		}
		delete []pHight;

		int max_area = 0, temp_area = 0;
		for (int row = 0; row <= row_sum; ++row)
		{
			temp_area = hight_len[row] * row;
			if (temp_area > max_area)
			{
				max_area = temp_area;
			}
		}

		return max_area;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int row = 5;
	int col = 5;
	int ones = 5;
	if ( argc > 3) {
		row = _wtoi(argv[1]);
		col = _wtoi(argv[2]);
		ones = _wtoi(argv[3]);
	}

	vector<vector<char> > matrix(row, vector<char>(col, '1'));
	matrix[0][3] = '0';
	matrix[3][0] = '0';
	matrix[3][1] = '0';
	matrix[3][2] = '0';
	matrix[4][4] = '0';
	/*srand(time(0));
	for(int i = 0; i< ones; ++i) {
		matrix[rand() % row][rand() % col] = '0';
	}*/

	cout<<"2D binary matrix:\n";
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout<<' '<<matrix[i][j];
		}
		cout<<endl;
	}
	cout<<endl;

	//system("pause");

	Solution so;
	int area = so.maximalRectangle(matrix);

	cout<<"area = "<<area<<endl;

	system("pause");

	return 0;
}

