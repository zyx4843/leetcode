// Source : https://oj.leetcode.com/problems/search-in-rotated-sorted-array/
// Author : zheng yi xiong 
// Date   : 2015-01-08

/********************************************************************************** 
* 
* Suppose a sorted array is rotated at some pivot unknown to you beforehand.

* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

* You are given a target value to search. If found in the array return its index, otherwise return -1.

* You may assume no duplicate exists in the array.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

class Solution {
public:
	int search(int A[], int n, int target) {
		int ibegin = 0, iend = n, imid = 0;
		while (ibegin != iend)
		{
			imid = (iend + ibegin) / 2;
			if (A[imid] == target)
			{
				return imid;
			}
			else if (target < A[imid])
			{
				if (A[ibegin] < A[imid])
				{
					if (target >= A[ibegin])
					{
						iend = imid;
					}
					else
					{
						ibegin = imid + 1;
					}
				}
				else
				{
					iend = imid;
				}
			}
			else
			{
				if (A[ibegin] < A[imid])
				{
					ibegin = imid + 1;
				}
				else
				{
					if (target >= A[ibegin])
					{
						iend = imid;
					}
					else
					{
						ibegin = imid + 1;
					}
				}
			}
		}

		return -1;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int A[] = {4, 5, 6, 7, 0, 1, 2};
	int n = 7;
	int target = 3;
	cout<<"rotated sorted array:\n";

	for(int i = 0; i < n; ++i) {
		cout<<" "<<A[i];
	}
	cout<<endl;

	cout<<"target value: "<<target<<endl;

	Solution so;
	int target_index = so.search(A, n, target);

	cout<<"target index: "<<target_index<<endl;

	system("pause");

	return 0;
}

