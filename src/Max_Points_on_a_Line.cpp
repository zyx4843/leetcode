// Source : https://oj.leetcode.com/problems/max-points-on-a-line/
// Author : zheng yi xiong 
// Date   : 2014-11-12

/********************************************************************************** 
* 
* Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*               
**********************************************************************************/


struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int num = points.size();
        if (2 >= num)
		{
			return num;
		}
		
		int maxPoint = 0;
		std::map<float, int> float_map;
		float float_tan = 0;
		int zero_count = 1;
		int two_zero = 0;
		for (int i = 0; i < num - 1; ++i)
		{
			for (int j = i + 1; j < num; ++j)
			{
				if (0 != points[j].x - points[i].x)
				{
					float_tan = (points[j].y - points[i].y) / (float)(points[j].x - points[i].x);
					if (float_map.find(float_tan) != float_map.end())
					{
						++float_map[float_tan];
					}
					else
					{
						float_map[float_tan] = 2;
					}
				}
				else if(points[j].y != points[i].y)
				{
					++zero_count;
				}
				else
				{
		        	++two_zero;
				}
			}

			for (std::map<float, int>::iterator it = float_map.begin(); it != float_map.end(); ++it)
			{
				if (maxPoint < it->second + two_zero)
				{
					maxPoint = it->second + two_zero;
				}
			}
			float_map.clear();

			if (maxPoint < zero_count + two_zero)
			{
				maxPoint = zero_count + two_zero;
			}
			zero_count = 1;
			
			if (maxPoint < two_zero + 1)
			{
				maxPoint = two_zero + 1;
			}
			two_zero = 0;
		}

		return maxPoint;
    }
};
