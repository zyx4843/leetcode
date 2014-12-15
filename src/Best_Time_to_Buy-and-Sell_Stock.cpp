// Source : https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Author : zheng yi xiong 
// Date   : 2014-12-15

/********************************************************************************** 
* 
* Say you have an array for which the ith element is the price of a given stock on day i.

* If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
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
		if (0 == len)
		{
			return 0;
		}

		int sumProfit = 0;
		int minIndex = 0;
		int tempProfit = 0;
		for (int i = 1; i < len; ++i)
		{
			tempProfit = prices[i] - prices[minIndex];
			if (0 > tempProfit)
			{
				minIndex = i;
			}
			else if (0 < tempProfit)
			{
				if (sumProfit < tempProfit)
				{
					sumProfit = tempProfit;
				}
			}
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

