// Source : https://oj.leetcode.com/problems/gas-station/
// Author : zheng yi xiong 
// Date   : 2014-12-05

/********************************************************************************** 
* 
* There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

* You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

* Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

* Note:
*  The solution is guaranteed to be unique.
*               
**********************************************************************************/
#include "stdafx.h"
#include <vector>

using namespace std;

class CGas_Station {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		if (gas.empty())
		{
			return -1;
		}

		int num = gas.size();
		if (1 == num)
		{
			return (0 <= (gas[0] - cost[0])) ? 0 : -1;
		}

		vector<int> remain_gas(num);
		vector<int> remain_pos(num);
		int temp_remain = 0;
		int index = 0;
		remain_gas[0] = gas[0] - cost[0];
		remain_pos[0] = 0;
		int remain_sum = remain_gas[0];
		for (int i = 1; i < num; ++i)
		{
			temp_remain = gas[i] - cost[i];
			if (0 <= (temp_remain ^ remain_gas[index]))
			{
				remain_gas[index] += temp_remain;
			}
			else
			{
				remain_gas[++index] = temp_remain;
				remain_pos[index] = i;
			}
			remain_sum += temp_remain;
		}

		if (0 > remain_sum)
		{
			return -1;
		}

		if (0 <= (remain_gas[index] ^ remain_gas[0]) )
		{
			remain_gas[0] += remain_gas[index];
			remain_pos[0] = remain_pos[index];
			--index;
		}

		for (int i = 0; i <= index; ++i)
		{
			if (0 <= remain_gas[i])
			{
				remain_sum = remain_gas[i];
				for (int j = i + 1; j < index; ++j)
				{
					remain_sum += remain_gas[j];
					if (0 > remain_sum)
					{
						break;
					}
				}

				if (0 <= remain_sum)
				{
					for (int j = 0; j < i; ++j)
					{
						remain_sum += remain_gas[j];
						if (0 > remain_sum)
						{
							break;
						}
					}

					if (0 <= remain_sum)
					{
						return remain_pos[i];
					}
				}
			}
		}

		return -1;
	}
};