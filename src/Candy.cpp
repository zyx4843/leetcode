// Source : https://oj.leetcode.com/problems/candy/
// Author : zheng yi xiong 
// Date   : 2014-12-04

/********************************************************************************** 
* 
* There are N children standing in a line. Each child is assigned a rating value.

* You are giving candies to these children subjected to the following requirements:

* Each child must have at least one candy.
* Children with a higher rating get more candies than their neighbors.
* What is the minimum candies you must give?
*               
**********************************************************************************/
#include "stdafx.h"
#include <vector>

using namespace std;

class CCandy {
public:
	int candy(vector<int> &ratings) {
		if (ratings.empty())
		{
			return 0;
		}
		int num = ratings.size();
		if (1 == num)
		{
			return 1;
		}
		int candyNum = 0;
		int increase_prev = 1;	//递增的前一个糖果数
		int decrease_count = 0;	//递减的个数
		int decrease_max = 0;
		int equel_num = 0;	//递增相等的个数
		int max_equel_num = 0;

		for (int i = 1; i < num; ++i)
		{
			if (ratings[i - 1] < ratings[i])
			{
				if (0 == decrease_count)
				{
					candyNum += increase_prev;
					++increase_prev;
				}
				else
				{
					if (increase_prev > decrease_max)
					{
						candyNum += (increase_prev - decrease_max) * (1 - max_equel_num);
					}
					increase_prev = 2;
					decrease_count = 0;
					decrease_max = 0;
					max_equel_num = 0;
				}
				equel_num = 0;
			}
			else if (ratings[i - 1] == ratings[i])
			{
				if (0 == decrease_count)
				{
					candyNum += increase_prev;
					increase_prev = 1;
					++equel_num;
				}
				else
				{
					candyNum += 1;
					decrease_count = 1;
				}
			}
			else
			{
				if (0 == decrease_count)
				{
					candyNum += 3;
					decrease_count = 2;
					decrease_max = 2;
					max_equel_num = equel_num;
				}
				else
				{
					++decrease_count;
					candyNum += decrease_count;
					++decrease_max;
				}
				equel_num = 0;
			}
		}

		if (0 == decrease_count)
		{
			if (ratings[num - 1] == ratings[num - 2])
			{
				candyNum += increase_prev;
				candyNum -= equel_num * (increase_prev - 1);
			}
			else
			{
				candyNum += increase_prev;
			}
		}
		else
		{
			if (increase_prev > decrease_max)
			{
				candyNum += (increase_prev - decrease_max) * (1 - max_equel_num);
			}
		}

		return candyNum;
	}
};