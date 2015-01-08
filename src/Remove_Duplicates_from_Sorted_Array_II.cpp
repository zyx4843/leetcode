// Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Author : zheng yi xiong 
// Date   : 2015-01-08

/********************************************************************************** 
* 
* Follow up for "Remove Duplicates":
* What if duplicates are allowed at most twice?

* For example,
* Given sorted array A = [1,1,1,2,2,3],

* Your function should return length = 5, and A is now [1,1,2,2,3].
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (0 >= n)
		{
			return 0;
		}

		int pos = 0;
		bool bCopy = true;
		for (int i = 1; i < n; ++i)
		{
			if (A[pos] != A[i])
			{
				A[++pos] = A[i];
				bCopy = true;
			}
			else if (bCopy)
			{
				bCopy = false;
				A[++pos] = A[i];
			}
		}

		return pos + 1;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int maxN = 5;
	int maxNumber = 3;
	if ( argc > 2) {
		maxN = _wtoi(argv[1]);
		maxNumber = _wtoi(argv[2]);
	}

	int *pA = new int[maxN * maxNumber];

	cout<<"sorted linked list:\n";

	int n = 0;
	srand(time(0));
	for(int i = 1; i < maxN; ++i) {
		int duplicate = rand() % maxNumber + 1;
		for (int j = 0; j < duplicate; ++j)
		{
			pA[n++] = i;
			cout<<" "<<pA[n - 1];
		}
	}
	cout<<endl;

	Solution so;
	int iRet = so.removeDuplicates(pA, n);

	cout<<"return array "<<iRet<<":\n ";
	for(int i = 0; i < iRet; ++i)
	{
		cout<<" "<<pA[i];
	}
	cout<<endl;
	delete []pA;

	system("pause");

	return 0;
}

