// Source : https://oj.leetcode.com/problems/surrounded-regions/
// Author : zheng yi xiong 
// Date   : 2014-12-09

/********************************************************************************** 
* 
* Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

* A region is captured by flipping all 'O's into 'X's in that surrounded region.

* For example,
* X X X X
* X O O X
* X X O X
* X O X X
* After running your function, the board should be:

* X X X X
* X X X X
* X X X X
* X O X X
*               
**********************************************************************************/
#include "stdafx.h"
#include <vector>
#include <stack>

using namespace std;

class CSurrounded_Regions {
public:
	void solve(vector<vector<char>> &board) {
		int row_sum = board.size();
		if (0 == row_sum)
		{
			return;
		}

		int col_sum = board[0].size();
		int sum = row_sum * col_sum;
		bool *pBVisit = new bool[sum];
		memset(pBVisit, 0, sizeof(bool) * sum);
		vector<char *> vec_board_addr;
		stack<int> stack_col;
		stack<int> stack_row;
		int row_begin = 0;
		bool bChange = true;
		int i = 0, j = 0;
		for (int row = 1; row < row_sum - 1; ++row)
		{
			row_begin = row * col_sum;
			for (int col = 1; col < col_sum - 1; ++col)
			{
				if ( ('O' == board[row][col]) && (!pBVisit[row_begin + col]))
				{
					bChange = true;
					pBVisit[row_begin + col] = true;
					stack_row.push(row);
					stack_col.push(col);

					while (!stack_row.empty())
					{
						i = stack_row.top();
						stack_row.pop();
						j = stack_col.top();
						stack_col.pop();
						//向上走
						if (1 == i)
						{
							if('X' != board[0][j])
							{
								bChange = false;
							}
						}
						else if ( ('X' != board[i - 1][j]) && (!pBVisit[(i - 1) * col_sum + j]) )
						{
							pBVisit[(i - 1) * col_sum + j] = true;
							stack_row.push(i - 1);
							stack_col.push(j);
						}

						//向左走
						if (1 == j)
						{
							if('X' != board[i][j - 1])
							{
								bChange = false;
							}
						}
						else if ( ('X' != board[i][j - 1]) && (!pBVisit[i * col_sum + j - 1]) )
						{
							pBVisit[i * col_sum + j - 1] = true;
							stack_row.push(i);
							stack_col.push(j - 1);
						}

						//向右走
						if (col_sum - 2 == j)
						{
							if('X' != board[i][j + 1])
							{
								bChange = false;
							}
						}
						else if ( ('X' != board[i][j + 1]) && (!pBVisit[i * col_sum + j + 1]) )
						{
							pBVisit[i * col_sum + j + 1] = true;
							stack_row.push(i);
							stack_col.push(j + 1);
						}

						//向下走
						if (row_sum - 2 == i)
						{
							if('X' != board[row_sum - 1][j])
							{
								bChange = false;
							}
						}
						else if ( ('X' != board[i + 1][j]) && (!pBVisit[(i + 1) * col_sum + j]) )
						{
							pBVisit[(i + 1) * col_sum + j] = true;
							stack_row.push(i + 1);
							stack_col.push(j);
						}

						if (bChange)
						{
							vec_board_addr.push_back(&board[i][j]);
						}
					}

					if (bChange)
					{
						for (vector<char *>::iterator it = vec_board_addr.begin(); it != vec_board_addr.end(); ++it)
						{
							*(*it) = 'X';
						}
					}

					vec_board_addr.clear();
				}
			}
		}

		delete []pBVisit;
	}
};