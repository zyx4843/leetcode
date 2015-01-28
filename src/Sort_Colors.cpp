// Source : https://oj.leetcode.com/problems/sort-colors/
// Author : zheng yi xiong 
// Date   : 2015-01-21

/********************************************************************************** 
* 
* Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

* Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

* Note:
* You are not suppose to use the library's sort function for this problem.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void sortColors(int A[], int n) {
		int color[3] = {0};
		for (int i = 0; i < n; ++i)
		{
			++color[A[i]];
		}
		int index = 0;
		for (int i = 0; i < color[0]; ++i)
		{
			A[index++] = 0;
		}

		for (int i = 0; i < color[1]; ++i)
		{
			A[index++] = 1;
		}

		for (int i = 0; i < color[2]; ++i)
		{
			A[index++] = 2;
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

