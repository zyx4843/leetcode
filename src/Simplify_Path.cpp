// Source : https://oj.leetcode.com/problems/simplify-path/
// Author : zheng yi xiong 
// Date   : 2015-01-28

/********************************************************************************** 
* 
* Given an absolute path for a file (Unix-style), simplify it.

* For example,
* path = "/home/", => "/home"
* path = "/a/./b/../../c/", => "/c"

* click to show corner cases.

* Corner Cases:
* Did you consider the case where path = "/../"?
* In this case, you should return "/".
* Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
* In this case, you should ignore redundant slashes and return "/home/foo".
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		if (path.empty())
		{
			return "/";
		}

		path.push_back('/');
		int len = path.length();
		vector<char> vec_path(len);
		vec_path[0] = '/';
		int vec_pos = 1, temp_pos = 1;
		int i = 0, j = 0;
		for (; i < len; ++i)
		{
			if ('/' == path[i])
			{
				if (vec_pos != temp_pos)
				{
					if ( (temp_pos - 1 == vec_pos) && ('.' == vec_path[temp_pos - 1]) )
					{
						//do nothing
					}
					else if ( (temp_pos - 2 == vec_pos) && ('.' == vec_path[temp_pos - 1]) && ('.' == vec_path[temp_pos - 2]) )
					{
						for (j = vec_pos - 2; j > 0; --j)
						{
							if ('/' == vec_path[j])
							{
								vec_pos = j + 1;
								vec_path[vec_pos] = 0;
								break;
							}
						}

						if (0 >= j)
						{
							vec_pos = 1;
							vec_path[1] = 0;
						}
					}
					else
					{
						vec_path[temp_pos++] = path[i];
						vec_pos = temp_pos;
					}
					temp_pos = vec_pos;
				}
			}
			else
			{
				vec_path[temp_pos++] = path[i];
			}
		}

		if ((1 != vec_pos) && ('/' == vec_path[vec_pos - 1]))
		{
			vec_path[vec_pos - 1] = 0;
		}
		else
		{
			vec_path[vec_pos] = 0;
		}

		return &vec_path[0];
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution so;
	string path = "/home/foo/.ssh/../.ssh2/authorized_keys";
	string realpath = so.simplifyPath(path);
	return 0;
}

