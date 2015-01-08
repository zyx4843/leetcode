// Source : https://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Author : zheng yi xiong 
// Date   : 2015-01-08

/********************************************************************************** 
* 
* Follow up for "Search in Rotated Sorted Array":
* What if duplicates are allowed?

* Would this affect the run-time complexity? How and why?

* Write a function to determine if a given target is in the array.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

class Solution {
public:
	bool search(int A[], int n, int target) {
		int ibegin = 0, iend = n, imid = 0;
		while (ibegin != iend)
		{
			imid = (iend + ibegin) / 2;
			if (A[imid] == target)
			{
				return true;
			}
			else if (target < A[imid])
			{
				if (A[ibegin] < A[imid])
				{
					if (target >= A[ibegin])
					{
						//ie.5,6,...9...,4 target: 7 or 5
						iend = imid;
					}
					else
					{
						//ie.5,6,...9...,4 target: 3
						ibegin = imid + 1;
					}
				}
				else if (A[ibegin] == A[imid])
				{
					//ie.5,5,...,5...4,5,5 target: 4
					++ibegin;
				}
				else
				{
					//ie.5,6,...3,4...,4 target: 2
					iend = imid;
				}
			}
			else
			{
				if (A[iend - 1] < A[imid])
				{
					//ie.5,5,...6,...,4 target: 8
					ibegin = imid + 1;
				}
				else if (A[iend - 1] == A[imid])
				{
					//ie.5,5,...,5...6,5,5 target: 6
					--iend;
				}
				else
				{
					if (target > A[iend - 1])
					{
						//ie.6,,...3,...,5 target: 8
						iend = imid;
					}
					else
					{
						//ie.6,,...3,...,5 target: 4
						ibegin = imid + 1;
					}
				}
			}
		}

		return false;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int A[] = {4, 5, 6, 7, 0, 1, 2, 3};
	int n = sizeof(A) / 4;
	int target = 3;
	cout<<"rotated sorted array:\n";

	for(int i = 0; i < n; ++i) {
		cout<<" "<<A[i];
	}
	cout<<endl;

	cout<<"target value: "<<target<<endl;

	Solution so;
	bool bTarget = so.search(A, n, target);

	if (bTarget)
	{
		cout<<"target in array"<<endl;
	}
	else
	{
		cout<<"target not in array"<<endl;
	}

	system("pause");

	return 0;
}

