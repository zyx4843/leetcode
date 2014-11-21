// Source : https://oj.leetcode.com/problems/reverse-words-in-a-string/
// Author : zheng yi xiong 
// Date   : 2014-11-10

/********************************************************************************** 
* 
* Given an input string, reverse the string word by word.

* For example,
* Given s = "the sky is blue",
* return "blue is sky the".

* Clarification:

* What constitutes a word?
* A sequence of non-space characters constitutes a word.

* Could the input string contain leading or trailing spaces?
* Yes. However, your reversed string should not contain leading or trailing spaces.

* How about multiple spaces between two words?
* Reduce them to a single space in the reversed string.
*               
**********************************************************************************/

class Solution {
public:
	void reverseWords(string &s) {
		if (s.empty())
		{
			return;
		}

		string str = s;
		int alphaNum = 0;
		s.clear();
		for (int i = str.length() - 1; i >= 0; --i)
		{
			if (' ' == str[i])
			{
				if (0 < alphaNum)
				{
					s.append(&str[i + 1], alphaNum);
					s.append(&str[i], 1);
					alphaNum = 0;
				}
			}
			else
			{
				++alphaNum;
			}
		}

		if (' ' != str[0])
		{
			s.append(&str[0], alphaNum);
		}
		else
		{
			if (s.length() > 0)
			{
				if (' ' == s[s.length() - 1])
				{
					s.erase(s.length() - 1, 1);
				}
			}
		}
	}
};