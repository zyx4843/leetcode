// Source : https://oj.leetcode.com/problems/word-search/
// Author : zheng yi xiong 
// Date   : 2015-01-08

/********************************************************************************** 
* 
* Given a 2D board and a word, find if the word exists in the grid.

* The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

* For example,
* Given board =

* [
*  ["ABCE"],
*  ["SFCS"],
*  ["ADEE"]
* ]
* word = "ABCCED", -> returns true,
* word = "SEE", -> returns true,
* word = "ABCB", -> returns false.
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

class Solution {
public:
	bool exist(vector<vector<char> > &board, string word) {
		if (board.empty() || board[0].empty())
		{
			return false;
		}

		int row_sum = board.size();
		int col_sum = board[0].size();
		int word_sum = word.size();
		vector<vector<bool>> vec_vec_ues(row_sum, vector<bool>(col_sum, false));
		for (int row = 0; row < row_sum; ++row)
		{
			for (int col = 0; col < col_sum; ++col)
			{
				if (board[row][col] == word[0] && !vec_vec_ues[row][col])
				{
					if (1 == word_sum)
					{
						return true;
					}

					vec_vec_ues[row][col] = true;
					if (Find(board, word, vec_vec_ues, row, col, 0, row_sum, col_sum, word_sum))
					{
						return true;
					}
					vec_vec_ues[row][col] = false;
				}
			}
		}


		return false;
	}
private:
	bool Find(vector<vector<char> > &board, string word, vector<vector<bool>> &vec_vec_ues, int row, int col, int word_index, int &row_sum, int &col_sum, int &word_sum)
	{
		bool bFind = false;
		if ((0 < row) && (!vec_vec_ues[row - 1][col]) && (board[row - 1][col] == word[word_index + 1]))
		{
			if (word_index == word_sum - 2)
			{
				return true;
			}
			vec_vec_ues[row - 1][col] = true;
			bFind = Find(board, word, vec_vec_ues, row - 1, col, word_index + 1, row_sum, col_sum, word_sum);
			vec_vec_ues[row - 1][col] = false;
		}

		if ((!bFind) && (0 < col) && (!vec_vec_ues[row][col - 1]) && (board[row][col - 1] == word[word_index + 1]))
		{
			if (word_index == word_sum - 2)
			{
				return true;
			}
			vec_vec_ues[row][col - 1] = true;
			bFind = Find(board, word, vec_vec_ues, row, col - 1, word_index + 1, row_sum, col_sum, word_sum);
			vec_vec_ues[row][col - 1] = false;
		}

		if ((!bFind) && (row_sum - 1 > row) && (!vec_vec_ues[row + 1][col]) && (board[row + 1][col] == word[word_index + 1]))
		{
			if (word_index == word_sum - 2)
			{
				return true;
			}
			vec_vec_ues[row + 1][col] = true;
			bFind = Find(board, word, vec_vec_ues, row + 1, col, word_index + 1, row_sum, col_sum, word_sum);
			vec_vec_ues[row + 1][col] = false;
		}

		if ((!bFind) && (col_sum - 1 > col) && (!vec_vec_ues[row][col + 1]) && (board[row][col + 1] == word[word_index + 1]))
		{
			if (word_index == word_sum - 2)
			{
				return true;
			}
			vec_vec_ues[row][col + 1] = true;
			bFind = Find(board, word, vec_vec_ues, row, col + 1, word_index + 1, row_sum, col_sum, word_sum);
			vec_vec_ues[row][col + 1] = false;
		}

		return bFind;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	string board_str = "ABCESFCSADEE";
	vector<vector<char> > board;
	for (int i = 0; i < 3; ++i)
	{
		vector<char> temp(&board_str[i * 4], &board_str[i * 4] + 4);
		board.push_back(temp);
	}
	string word = "ABCCED"/*"SEE"*//*"ABCB"*/;
	Solution so;
	bool bexist = so.exist(board, word);
	return 0;
}

