// Source : https://oj.leetcode.com/problems/text-justification/
// Author : zheng yi xiong 
// Date   : 2015-01-31

/********************************************************************************** 
* 
* Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

* You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

* Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

* For the last line of text, it should be left justified and no extra space is inserted between words.

* For example,
* words: ["This", "is", "an", "example", "of", "text", "justification."]
* L: 16.

* Return the formatted lines as:
* [
*  "This    is    an",
*  "example  of text",
*  "justification.  "
* ]
* Note: Each word is guaranteed not to exceed L in length.

* click to show corner cases.

* Corner Cases:
*  A line other than the last line might contain only one word. What should you do in this case?
*  In this case, that line should be left-justified.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> retVec;
		if (words.empty())
		{
			return retVec;
		}

		int retNo = 0, wordStart = 0, wordEnd = 1, stringLen = words[0].length() + 1;
		int extraNum = 0, eachExtra = 0, moreExtra = 0;
		int i = 1;
		for (; i < words.size(); ++i)
		{
			if (stringLen + words[i].length() > L)
			{
				extraNum = L - stringLen + 1;
				if (1 < wordEnd - wordStart)
				{
					eachExtra = extraNum / (wordEnd - wordStart - 1) + 1;
					moreExtra = extraNum % (wordEnd - wordStart - 1);
					retVec.push_back(words[wordStart++]);
					for (int j = 0; j < moreExtra; ++j)
					{
						for (int k = 0; k < eachExtra + 1; ++k)
						{
							retVec[retNo].push_back(' ');
						}
						retVec[retNo] += words[wordStart++];
					}

					for (; wordStart < wordEnd; ++wordStart)
					{
						for (int k = 0; k < eachExtra; ++k)
						{
							retVec[retNo].push_back(' ');
						}
						retVec[retNo] += words[wordStart];
					}
				}
				else
				{
					retVec.push_back(words[wordStart]);
					for (int j = 0; j < extraNum; ++j)
					{
						retVec[retNo].push_back(' ');
					}
				}
				++retNo;
				wordStart = i;
				stringLen = 0;
			}
			stringLen += words[i].length() + 1;
			wordEnd = i + 1;
		}

		extraNum = L - stringLen + 1;
		retVec.push_back(words[wordStart++]);
		for (; wordStart < wordEnd; ++wordStart)
		{
			retVec[retNo].push_back(' ');
			retVec[retNo] += words[wordStart];
		}

		for (int j = 0; j < extraNum; ++j)
		{
			retVec[retNo].push_back(' ');
		}

		return retVec;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> words;
	words.push_back("This");
	words.push_back("is");
	words.push_back("an");
	words.push_back("example");
	words.push_back("of");
	words.push_back("text");
	words.push_back("justification.");
	Solution so;
	vector<string> vecRet = so.fullJustify(words, 16);
	return 0;
}

