// Source : https://oj.leetcode.com/problems/merge-intervals/
// Author : zheng yi xiong 
// Date   : 2015-02-12

/********************************************************************************** 
* 
* Given a collection of intervals, merge all overlapping intervals.

* For example,
* Given [1,3],[2,6],[8,10],[15,18],
* return [1,6],[8,10],[15,18].
*             
**********************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
		if (intervals.empty())
		{
			return intervals;
		}

		vector<Interval> ret_intervals;
		ret_intervals.push_back(intervals.front());

		for (vector<Interval>::iterator it = intervals.begin() + 1; it != intervals.end(); ++it)
        {
			if (ret_intervals.back().end < it->start)
			{
				ret_intervals.push_back(*it);
			}
			else if (ret_intervals[0].start > it->end)
			{
				ret_intervals.insert(ret_intervals.begin(), *it);
			}
			else if (ret_intervals[0].start > it->start && (ret_intervals.back().end < it->end))
			{
				ret_intervals.clear();
				ret_intervals.push_back(*it);
			}
			else
			{
				bool bFindStart = false;
				for (vector<Interval>::iterator ret_it = ret_intervals.begin(); ret_it != ret_intervals.end(); )
				{
					if ( (!bFindStart) && (it->start <= ret_it->end) )
					{
						if (it->end < ret_it->start)
						{
							ret_intervals.insert(ret_it, *it);
							break;
						}
						else if (it->start <= ret_it->start)
						{
							ret_it->start = it->start;
							if (it->end <= ret_it->end)
							{
								break;
							}
							ret_it->end = it->end;
						}
						else if (it->end <= ret_it->end)
						{
							break;
						}
						else
						{
							ret_it->end = it->end;
						}

						bFindStart = true;
						++ret_it;
					}
					else if (bFindStart)
					{
						if (ret_it->start > it->end)
						{
							break;
						}
						else if (ret_it->end < it->end)
						{
							ret_it = ret_intervals.erase(ret_it);
						}
						else
						{
							it->end = ret_it->end;
							ret_it = ret_intervals.erase(ret_it);
							--ret_it;
							ret_it->end = it->end;
							break;
						}
					}
					else
					{
						++ret_it;
					}
				}
			}
        }

		return ret_intervals;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<Interval> intervals(4);
	intervals[0].start = 1;
	intervals[0].end = 3;
	intervals[1].start = 2;
	intervals[1].end = 6;
	intervals[2].start = 8;
	intervals[2].end = 10;
	intervals[3].start = 15;
	intervals[3].end = 18;
	Solution so;
	vector<Interval> ret = so.merge(intervals);
	return 0;
}

