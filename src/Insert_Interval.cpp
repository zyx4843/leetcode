// Source : https://oj.leetcode.com/problems/insert-interval/
// Author : zheng yi xiong 
// Date   : 2015-02-10

/********************************************************************************** 
* 
* Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

* You may assume that the intervals were initially sorted according to their start times.

* Example 1:
* Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

* Example 2:
* Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

* This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		if (intervals.empty() || (intervals.back().end < newInterval.start) )
		{
			intervals.push_back(newInterval);
			return intervals;
		}

		if (intervals[0].start > newInterval.end)
		{
			intervals.insert(intervals.begin(), newInterval);
			return intervals;
		}

		if (intervals[0].start > newInterval.start && (intervals.back().end < newInterval.end))
		{
			intervals.clear();
			intervals.push_back(newInterval);
			return intervals;
		}

		bool bFindStart = false;
		for (vector<Interval>::iterator it = intervals.begin(); it != intervals.end(); )
        {
			if ( (!bFindStart) && (newInterval.start <= it->end) )
			{
				if (newInterval.end < it->start)
				{
					intervals.insert(it, newInterval);
					return intervals;
				}
				else if (newInterval.start <= it->start)
				{
					it->start = newInterval.start;
					if (newInterval.end <= it->end)
					{
						return intervals;
					}
					it->end = newInterval.end;
				}
				else if (newInterval.end <= it->end)
				{
					return intervals;
				}
				else
				{
					it->end = newInterval.end;
				}

				bFindStart = true;
				++it;
			}
			else if (bFindStart)
			{
				if (it->start > newInterval.end)
				{
					return intervals;
				}
				else if (it->end < newInterval.end)
				{
					it = intervals.erase(it);
				}
				else
				{
					newInterval.end = it->end;
					it = intervals.erase(it);
					--it;
					it->end = newInterval.end;
					return intervals;
				}
			}
			else
			{
				++it;
			}
        }

		return intervals;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<Interval> intervals(2);
	intervals[0].start = 3;
	intervals[0].end = 5;
	intervals[1].start = 12;
	intervals[1].end = 15;
	/*intervals[2].start = 6;
	intervals[2].end = 7;
	intervals[3].start = 8;
	intervals[3].end = 10;
	intervals[4].start = 12;
	intervals[4].end = 16;*/
	Interval newInterval(6, 6);
	Solution so;
	vector<Interval> ret = so.insert(intervals, newInterval);
	return 0;
}

