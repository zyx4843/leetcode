// Source : https://oj.leetcode.com/problems/pascals-triangle-ii/
// Author : zheng yi xiong 
// Date   : 2014-12-16

/********************************************************************************** 
* 
* Given an index k, return the kth row of the Pascal's triangle.

* For example, given k = 3,
* Return [1,3,3,1].

* Note:
* Could you optimize your algorithm to use only O(k) extra space?
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> triangle_row(rowIndex + 1);
		triangle_row[0] = 1;
		if (0 == rowIndex)
		{
			return triangle_row;
		}

		for (int i = 1; i <= rowIndex; ++i)
		{
			triangle_row[1] = i;
			int j = 2;
			for (; j <= i / 2; ++j)
			{
				triangle_row[j] = triangle_row[i - j] + triangle_row[j];
			}

			for (; j <= i; ++j)
			{
				triangle_row[j] = triangle_row[i - j];
			}
		}

		return triangle_row;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 6;
	if ( argc > 1) {
		n = _wtoi(argv[1]);
	}

	Solution so;
	vector<int> pascal_row = so.getRow(n);

	cout<< "numRows = "<<n<<endl<<"pascal row: [ \n";
	cout<< "         [ ";
	for (int j = 0; j < n; ++j)
	{
		cout<<pascal_row[j]<< ", ";
	}
	cout<<pascal_row[n]<< " ]\n";

	system("pause");

	return 0;
}

