// Source : https://leetcode.com/problems/n-queens-ii/
// Author : zheng yi xiong 
// Date   : 2015-09-12

/********************************************************************************** 
* 
* Follow up for N-Queens problem.

* Now, instead outputting board configurations, return the total number of distinct solutions.

*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int totalNQueens(int n) {
		vector<char> col_vec(n, 0);		//该列是否被占用了
		vector<int> solve(n, -1);		//正确的列号
		int row = 0, col = 0;
		bool bEate = false;
		int total = 0;

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
					++total;
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

		return total;
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	int queensNumber = 4;
	Solution so;
	int ret = so.totalNQueens(queensNumber);
	printf("%d queens total %d solution\n", queensNumber, ret);
	system("pause");
	return 0;
}

