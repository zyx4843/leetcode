// Source : https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Author : zheng yi xiong 
// Date   : 2014-12-15

/********************************************************************************** 
* 
* Say you have an array for which the ith element is the price of a given stock on day i.

* Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again)
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
		int sumProfit = 0;
		int minPrice = 0;
		int index = 1;
		int len = prices.size();
		while (index < len)
		{
			while ((index < len) && (prices[index - 1] > prices[index])) ++index;
			minPrice = prices[index - 1];
			while ((index < len) && (prices[index - 1] <= prices[index])) ++index;
			sumProfit += prices[index - 1] - minPrice;
		}

		return sumProfit;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 10;
	int maxNumber = 100;
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

