// Source : https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Author : zheng yi xiong 
// Date   : 2014-11-6

/********************************************************************************** 
* 
* Suppose a sorted array is rotated at some pivot unknown to you beforehand.

* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

* Find the minimum element.

* You may assume no duplicate exists in the array.
*               
**********************************************************************************/

class Solution {
public:
	int findMin(vector<int> &num) {
		int big = num.size();	//head or tail where is large
		if (0 == big)
		{
			return 0;
		}
		else if (1 == big)
		{
			return num[0];
		}
		else if (2 == big)
		{
			if (num[0] < num[1])
			{
				return num[0];
			}
			else
			{
				return num[1];
			}
		}

		big	= big - 1;
		int little = 0;		//head or tail where is little

		if (num[little] > num[big])
		{
			little = big;
			big = 0;
		}
		int mid = big / 2;
		int newMid = mid;
		do 
		{
			mid = newMid;
			if (num[mid] < num[little])
			{
				little = mid;
			}
			else
			{
				big = mid;
			}
			newMid = (little + big) / 2;
		} while (newMid != mid);

		if (num[mid] < num[little])
		{
			return num[mid];
		}
		else
		{
			return num[little];
		}
	}
};