// Source : https://oj.leetcode.com/problems/length-of-last-word/
// Author : zheng yi xiong 
// Date   : 2015-02-10

/********************************************************************************** 
* 
* Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

* If the last word does not exist, return 0.

* Note: A word is defined as a character sequence consists of non-space characters only.

* For example, 
* Given s = "Hello World",
* return 5.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(const char *s) {
		int strLen = strlen(s);
		bool bFindChar = true;
		int wordLen = 0;
		for (int i = strLen - 1; i >= 0; --i)
		{
			if ( ('a' <= s[i] && 'z' >= s[i]) || ('A' <= s[i] && 'Z' >= s[i]) )
			{
				if (bFindChar)
				{
					bFindChar = false;
				}
				++wordLen;
			}
			else
			{
				if (!bFindChar)
				{
					break;
				}
			}
		}

		return wordLen;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution so;
	int wordLen = so.lengthOfLastWord("Hello World");
	return 0;
}

