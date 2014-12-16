// Source : https://oj.leetcode.com/problems/triangle/
// Author : zheng yi xiong 
// Date   : 2014-12-16

/********************************************************************************** 
* 
* Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

* For example, given the following triangle
* [
*    [2],
*   [3,4],
*  [6,5,7],
* [4,1,8,3]
* ]
* The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

* Note:
* Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int row = triangle.size();
		if (0 == row)
		{
			return 0;
		}
		vector<int> miniMum(row);
		for (int i = 0; i < row; ++i)
		{
			miniMum[i] = triangle[row - 1][i];
		}

		for (int i = row - 2; 0 <= i; --i)
		{
			for (int j = 0; j <= i; ++j)
			{
				miniMum[j] = min(triangle[i][j] + miniMum[j], triangle[i][j] + miniMum[j + 1]);
			}
		}

		return miniMum[0];
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 20;
	int maxNumber = 20;
	if ( argc > 2) {
		n = _wtoi(argv[1]);
		maxNumber = _wtoi(argv[2]);
	}

	vector<vector<int>> triangle(n, vector<int>(n));

	srand(time(0));
	cout<< "triangle: [ \n";
	for(int i=0; i< n - 1; ++i) {
		cout<< "         [ ";
		for (int j = 0; j < i; ++j)
		{
			triangle[i][j] = rand() % maxNumber;
			cout<<triangle[i][j]<< ", ";
		}
		triangle[i][i] = rand() % maxNumber;
		cout<<triangle[i][i]<< " ]\n";
	}
	cout<<"      ]\n";

	Solution so;
	int minimum = so.minimumTotal(triangle);
	cout<<"minimum ="<<minimum<<endl;

	system("pause");

	return 0;
}

