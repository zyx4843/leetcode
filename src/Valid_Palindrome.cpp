// Source : https://oj.leetcode.com/problems/valid-palindrome/
// Author : zheng yi xiong 
// Date   : 2014-12-15

/********************************************************************************** 
* 
* Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

* For example,
* "A man, a plan, a canal: Panama" is a palindrome.
* "race a car" is not a palindrome.

* Note:
* Have you consider that the string might be empty? This is a good question to ask during an interview.

* For the purpose of this problem, we define empty string as valid palindrome.
*               
**********************************************************************************/
#include "stdafx.h"
#include <string>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int i = 0;
		int j = s.length() - 1;
		while(i < j)
		{
			while( (!isAlphanumeric(s[i])) && (i < j) ) ++i;
			while( (!isAlphanumeric(s[j])) && (i < j) ) --j;
			if (s[i] != s[j])
			{
				break;
			}
			else
			{
				++i;
				--j;
			}
		}

		if (i < j)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
private:
	bool isAlphanumeric(char &c)
	{
		if ( (('0' <= c) && ('9' >= c)) || (('a' <= c) && ('z' >= c)) )
		{
			return true;
		}
		else if(('A' <= c) && ('Z' >= c))
		{
			c += 32; 
			return true;
		}
		else
		{
			return false;
		}
	}
};