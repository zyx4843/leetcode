// Source : https://leetcode.com/problems/n-queens/
// Author : zheng yi xiong 
// Date   : 2015-09-12

/********************************************************************************** 
* 
* The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

* Given an integer n, return all distinct solutions to the n-queens puzzle.

* Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

* For example,
* There exist two distinct solutions to the 4-queens puzzle:

* [
*   [".Q..",  // Solution 1
*    "...Q",
*    "Q...",
*    "..Q."],

*   ["..Q.",  // Solution 2
*    "Q...",
*    "...Q",
*    ".Q.."]
* ]
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<char> col_vec(n, 0);		//该列是否被占用了
		vector<int> solve(n, -1);		//正确的列号
		int sol = 0;
		int row = 0, col = 0;
		bool bEate = false;
		int index = 0;

		vector<vector<string>> ret_vec;

			for (row = 0; 0 <= row; )
			{
				for (col = solve[row] + 1; col < n; ++col)
				{
					//判断是否可位置是否会被其他皇后吃到
					if (0 == col_vec[col])
					{
						bEate = false;
						for (int i = 0; i < row; ++i)
						{
							if (col - (row - i) == solve[i])
							{
								bEate = true;
								break;
							}

							if (col + (row - i) == solve[i])
							{
								bEate = true;
								break;
							}
						}

						if (!bEate)
						{
							solve[row] = col;
							col_vec[col] = 1;
							break;
						}
					}
				}

				if (col < n)
				{
					++row;
					if (row == n)
					{
						vector<string> str_vec;
						for (int i = 0; i < n; ++i)
						{
							string str(n, '.');
							str[solve[i]] = 'Q';
							str_vec.push_back(str);
						}
						ret_vec.push_back(str_vec);
						--row;
						col_vec[solve[row]] = 0;
					}
				}
				else
				{
					//返回上步时被改的值要恢复
					if ((0 <= row - 1) && (0 <= solve[row - 1]))
					{
						col_vec[solve[row - 1]] = 0;
					}
					solve[row] = -1;
					--row;
				}
			}

		return ret_vec;
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution so;
	vector<vector<string>> ret = so.solveNQueens(1);
	for (int i = 0; i < ret.size(); ++i)
	{
		printf("[\n");
		for (int j = 0; j < ret[i].size(); ++j)
		{
			printf("   %s,\n", ret[i][j]);
		}
		printf("]\n\n");
	}
	system("pause");
	return 0;
}

