// Source : https://oj.leetcode.com/problems/valid-number/
// Author : zheng yi xiong 
// Date   : 2015-02-02

/********************************************************************************** 
* 
* Validate if a given string is numeric.

* Some examples:
* "0" => true
* " 0.1 " => true
* "abc" => false
* "1 a" => false
* "2e10" => true
* Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

* click to show spoilers.

* Update (2014-12-06):
* New test cases had been added. Thanks unfounder's contribution.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool isNumber(const char *s) {
		enum InputType {
			SPACE,
			DIGIT,
			EXPONENT,
			DOT,
			SIGN,
			NUM_INPUTS
		};
		const int number_state_map[][NUM_INPUTS] = {
		  //space,0~9, e,  .,   +-,
			 0,	   1,  -1,  2,  3,
			 5,	   1,   4,  7, -1,
			-1,	   7,  -1, -1, -1,
			-1,    1,  -1,  2, -1,
			-1,    8,  -1, -1,  6,
			 5,   -1,  -1, -1, -1,
			-1,    8,  -1, -1, -1,
			 5,    7,   4, -1, -1,
			 5,    8,  -1, -1, -1,
		};

		int state = 0;
		for (int i = 0; 0 != s[i]; ++i)
		{
			if (' ' == s[i])
			{
				state = number_state_map[state][SPACE];
			}
			else if ('0' <= s[i] && '9' >= s[i])
			{
				state = number_state_map[state][DIGIT];
			}
			else if ('e' == s[i] || 'E' == s[i])
			{
				state = number_state_map[state][EXPONENT];
			}
			else if ('.' == s[i])
			{
				state = number_state_map[state][DOT];
			}
			else if ('-' == s[i] || '+' == s[i])
			{
				state = number_state_map[state][SIGN];
			}
			else
			{
				return false;
			}

			if (-1 == state)
			{
				return false;
			}
		}

		if (1 == state || 5 == state || 7 == state || 8 == state)
		{
			return true;
		}

		return false;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	string s = ". 1";
	Solution so;
	bool bNumber = so.isNumber(s.c_str());
	return 0;
}

