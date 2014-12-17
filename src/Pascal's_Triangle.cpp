// Source : https://oj.leetcode.com/problems/pascals-triangle/
// Author : zheng yi xiong 
// Date   : 2014-12-16

/********************************************************************************** 
* 
* Given numRows, generate the first numRows of Pascal's triangle.

* For example, given numRows = 5,
* Return

* [
*      [1],
*     [1,1],
*    [1,2,1],
*   [1,3,3,1],
*  [1,4,6,4,1]
* ]
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		if (0 == numRows)
		{
			vector<vector<int> > triangle;
			return triangle;
		}

		vector<vector<int> > triangle(numRows);
		triangle[0].push_back(1);
		for (int i = 1; i < numRows; ++i)
		{
			triangle[i].push_back(1);
			int j = 1;
			for (; j <= i / 2; ++j)
			{
				triangle[i].push_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);
			}

			for (; j <= i; ++j)
			{
				triangle[i].push_back(triangle[i][i - j]);
			}
		}

		return triangle;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 8;
	if ( argc > 1) {
		n = _wtoi(argv[1]);
	}

	Solution so;
	vector<vector<int> > pascal_triangle = so.generate(n);

	cout<< "numRows = "<<n<<endl<<"triangle: [ \n";
	for(int i= 0; i< n; ++i) {
		cout<< "         [ ";
		for (int j = 0; j < i; ++j)
		{
			cout<<pascal_triangle[i][j]<< ", ";
		}
		cout<<pascal_triangle[i][i]<< " ]\n";
	}
	cout<<"      ]\n";

	system("pause");

	return 0;
}

