// Source : https://oj.leetcode.com/problems/merge-sorted-array/
// Author : zheng yi xiong 
// Date   : 2015-01-06

/********************************************************************************** 
* 
* Given two sorted integer arrays A and B, merge B into A as one sorted array.

* Note:
*  You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>

using namespace std;

class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		if (0 == n)
		{
			return;
		}

		if (0 == m)
		{
			memcpy(A, B, sizeof(int) * n);
			return;
		}

		memmove(&A[n], &A[0], sizeof(int) * m);
		int unit = 0, a = n, b = 0;
		for (; (unit < m + n) && (a < m + n) && (b < n); ++unit)
		{
			if (A[a] < B[b])
			{
				A[unit] = A[a++];
			}
			else
			{
				A[unit] = B[b++];
			}
		}

		if ( (unit < m + n) && (b < n) )
		{
			while (b < n)
			{
				A[unit++] = B[b++];
			}
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int m = 9;
	int n = 6;

	int A[15] = {1, 4, 5, 7, 9, 13, 23, 45, 67};
	int B[] = {2, 6, 8, 33, 56, 87};

	Solution so;
	so.merge(A, m, B, n);

	return 0;
}

