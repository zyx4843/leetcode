// Source : https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Author : zheng yi xiong 
// Date   : 2014-12-16

/********************************************************************************** 
* 
* Say you have an array for which the ith element is the price of a given stock on day i.

* Design an algorithm to find the maximum profit. You may complete at most two transactions.

* Note:
*  You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int len = prices.size();
		if (1 >= len)
		{
			return 0;
		}

		vector<int> vec_prev_max(len);
		vector<int> vec_last_max(len);
		int min_price = prices[0];
		vec_prev_max[0] = 0;
		for (int i = 1; i < len; ++i)
		{
			vec_prev_max[i] = max(vec_prev_max[i - 1], prices[i] - min_price);
			min_price = min(min_price, prices[i]);
		}

		int max_price = prices[len - 1];
		vec_last_max[len - 1] = 0;
		for (int i = len - 2; 0 <= i; --i)
		{
			vec_last_max[i] = max(vec_last_max[i + 1], max_price - prices[i]);
			max_price = max(max_price, prices[i]);
		}

		int max_profit = 0;
		for (int i = 0; i < len; ++i)
		{
			max_profit = max(max_profit, vec_prev_max[i] + vec_last_max[i]);
		}

		return max_profit;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 20;
	int maxNumber = 20;
	if ( argc > 2) {
		n = _wtoi(argv[1]);
		maxNumber = _wtoi(argv[2]);
	}

	vector<int> prices;

	srand(time(0));
	cout<< "prices: [ ";
	for(int i=0; i< n - 1; i++) {
		prices.push_back(rand() % maxNumber);
		cout<<prices[i]<< ", ";
	}

	prices.push_back(rand() % maxNumber);
	cout<<prices[n - 1]<<"]\n";

	Solution so;
	int maxPrices = so.maxProfit(prices);
	cout<<"maxprices ="<<maxPrices<<endl;

	system("pause");

	return 0;
}

