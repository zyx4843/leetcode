// Source : https://oj.leetcode.com/problems/decode-ways/
// Author : zheng yi xiong 
// Date   : 2015-01-05

/********************************************************************************** 
* 
* A message containing letters from A-Z is being encoded to numbers using the following mapping:

* 'A' -> 1
* 'B' -> 2
* ...
* 'Z' -> 26
* Given an encoded message containing digits, determine the total number of ways to decode it.

* For example,
* Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

* The number of ways decoding "12" is 2.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s.empty() || ('0' == s[0]) )
		{
			return 0;
		}

		int len = s.size();
		vector<int> vec_decode(len + 1, 0);
		vec_decode[0] = 1;
		vec_decode[1] = 1;

		for (int i = 1; i < len; ++i)
		{
			if ('0' == s[i])
			{
				if ('0' == s[i - 1] || '2' < s[i - 1])
				{
					return 0;
				}
				vec_decode[i + 1] = vec_decode[i - 1];
			}
			else if ( ('1' == s[i - 1]) || ('2' == s[i - 1] && '6' >= s[i]) )
			{
				vec_decode[i + 1] = vec_decode[i] + vec_decode[i - 1];
			}
			else
			{
				vec_decode[i + 1] = vec_decode[i];
			}
		}

		return vec_decode[len];
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	string s = "1212";
	Solution so;
	int numDecode = so.numDecodings(s);
	return 0;
}

