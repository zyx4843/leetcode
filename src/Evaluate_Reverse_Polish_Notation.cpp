// Source : https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/
// Author : zheng yi xiong 
// Date   : 2014-11-11

/********************************************************************************** 
* 
* Evaluate the value of an arithmetic expression in Reverse Polish Notation.

* Valid operators are +, -, *, /. Each operand may be an integer or another expression.

* Some examples:
* ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
* ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*               
**********************************************************************************/

class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		int len = tokens.size();
		if (1 == len)
		{
			return atoi(tokens[0].c_str());
		}

		int *pIteger = new int[len / 2 + 1];
		int index = 1;
		pIteger[0] = atoi(tokens[0].c_str());
		pIteger[1] = atoi(tokens[1].c_str());
		for (int i = 2; i < len; ++i)
		{
			if (1 == tokens[i].length())
			{
				if ("+" == tokens[i])
				{
					pIteger[index - 1] = pIteger[index - 1] + pIteger[index];
					--index;
				}
				else if ("-" == tokens[i])
				{
					pIteger[index - 1] = pIteger[index - 1] - pIteger[index];
					--index;
				}
				else if ("*" == tokens[i])
				{
					pIteger[index - 1] = pIteger[index - 1] * pIteger[index];
					--index;
				}
				else if ("/" == tokens[i])
				{
					pIteger[index - 1] = pIteger[index - 1] / pIteger[index];
					--index;
				}
				else
				{
					pIteger[++index] = atoi(tokens[i].c_str());
				}
			}
			else
			{
				pIteger[++index] = atoi(tokens[i].c_str());
			}
		}

		len = pIteger[0];
		delete []pIteger;

		return len;
	}
};