// Source : https://oj.leetcode.com/problems/add-binary/
// Author : zheng yi xiong 
// Date   : 2015-02-05

/********************************************************************************** 
* 
* Given two binary strings, return their sum (also a binary string).

* For example,
* a = "11"
* b = "1"
* Return "100".
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		string s = a;
		int i = a.length() - 1, j = b.length() - 1;
		bool bCarry = false;
		for (; 0 <= i && 0 <= j; --i, --j)
		{
			if ('1' == a[i] && '1' == b[j])
			{
				if (bCarry)
				{
					s[i] = '1';
				}
				else
				{
					s[i] = '0';
					bCarry = true;
				}
			}
			else if ('0' == a[i] && '0' == b[j])
			{
				if (bCarry)
				{
					s[i] = '1';
					bCarry = false;
				}
				else
				{
					s[i] = '0';
				}
			}
			else
			{
				if (bCarry)
				{
					s[i] = '0';
				}
				else
				{
					s[i] = '1';
				}
			}
		}

		if (0 > i)
		{
			for (; 0 <= j; --j)
			{
				if (bCarry)
				{
					if ('0' == b[j])
					{
						s.insert(s.begin(), '1');
						bCarry = false;
					}
					else
					{
						s.insert(s.begin(), '0');
					}
				}
				else
				{
					s.insert(s.begin(), b[j]);
				}
			}
		}
		else if (0 > j)
		{
			for (; 0 <= i; --i)
			{
				if (bCarry)
				{
					if ('0' == a[i])
					{
						s[i] = '1';
						bCarry = false;
					}
					else
					{
						s[i] = '0';
					}
				}
			}
		}

		if (bCarry)
		{
			s.insert(s.begin(), '1');
		}

		return s;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	string a = "11";
	string b = "1";
	Solution so;
	string s = so.addBinary(a, b);
	return 0;
}

