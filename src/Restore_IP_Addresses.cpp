// Source : https://oj.leetcode.com/problems/restore-ip-addresses/
// Author : zheng yi xiong 
// Date   : 2014-12-30

/********************************************************************************** 
* 
* Given a string containing only digits, restore it by returning all possible valid IP address combinations.

* For example:
* Given "25525511135",

* return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> vec_str;
		int len = s.length();
		if (4 > len || 12 < len)
		{
			return vec_str;
		}

		int ip1 = (0 < (len - 10)) ? (len - 10) : 0;
		for ( ; (len - ip1 > 3) && ( (ip1 < 2) || ((2 == ip1) && IsIpAddress(s, 0)) ); ++ip1)
		{
			if ((0 < ip1) && ('0' == s[0]))
			{
				continue;
			}

			int ip2 = (ip1 + 1 < (len - 7))? (len - 7) : (ip1 + 1);
			for (; (len - ip2 > 2)&& ( (ip2 < 3 + ip1) || ((ip2 == 3 + ip1) && IsIpAddress(s, ip1 + 1)) ); ++ip2)
			{
				if ( (ip2 > ip1 + 1) && ('0' == s[ip1 + 1]))
				{
					continue;
				}

				int ip3 = (ip2 + 1 < (len - 4))? (len - 4) : (ip2 + 1);
				for (; (len - ip3 > 1) && ( (ip3 < 3 + ip2) || ((ip3 == 3 + ip2) && IsIpAddress(s, ip2 + 1)) ); ++ip3)
				{
					if ((ip3 > ip2 + 1) && ('0' == s[ip2 + 1]))
					{
						continue;
					}

					if (('0' == s[ip3 + 1]) && (len > ip3 + 2))
					{
						continue;
					}

					if (4 > len - ip3 || IsIpAddress(s, ip3 + 1) )
					{
						string str_ip = s.substr(0, ip1 + 1);
						str_ip += '.';
						str_ip += s.substr(ip1 + 1, ip2 - ip1);
						str_ip += '.';
						str_ip += s.substr(ip2 + 1, ip3 - ip2);
						str_ip += '.';
						str_ip += s.substr(ip3 + 1, len - ip3 - 1);
						vec_str.push_back(str_ip);
					}
				}
			}
		}

		return vec_str;
	}
private:
	bool IsIpAddress(string &s, int pos)
	{
		if ('2' > s[pos])
		{
			return true;
		}
		else if ('2' == s[pos])
		{
			if ('5' > s[pos + 1])
			{
				return true;
			}
			else if ('5' == s[pos + 1] && '5' >= s[pos + 2])
			{
				return true;
			}
		}
		return false;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	string s = "25525511135";

	Solution so;
	vector<string> vec_str = so.restoreIpAddresses(s);
	return 0;
}

