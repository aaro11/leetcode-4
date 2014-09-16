
#include <vector>
using namespace std;

//Definition for a point.
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution 
{
private:
	int m_k;
	int m_b;

	inline void set_k_b(Point p1, Point p2)
	{
		if ((p1.x - p2.x) == 0)
		{
			m_k = 0;
		}
		else
		{
			m_k = (p1.y - p2.y) / (p1.x - p2.x);
		}
		m_b = p1.y - m_k*p1.x;				// b = y2 - k*x2;
	}

	inline bool isInLine(Point p)
	{
		return p.y == m_k * p.x + m_b;
	}

	int getCountInLine(vector<Point> points)
	{
		int count = 0;
		int len = points.size();
		for (int i = 0; i<len; i++)
		{
			if (isInLine(points[i]))
			{
				count++;
			}
		}
		return count;
	}



public:
	int maxPoints(vector<Point> &points)
	{
		int max = 0;
		int len = points.size();
		if (len == 1)
			return 1;
		for (int i = 0; i<len; i++)
		{
			for (int j = i + 1; j<len; j++)
			{
				// 在通过点求直线 k b
				set_k_b(points[i], points[j]);

				// 然后遍历其他点在直线上的数量
				int count = getCountInLine(points);
				if (max < count)
				{
					max = count;
				}
			}

		}
		return max;
	}
};

int main()
{


	vector<Point> points;
	points.push_back(Point(29, 87));
	points.push_back(Point(145, 227));
	points.push_back(Point(400, 84));
	points.push_back(Point(800, 179));
	points.push_back(Point(60, 950));
	points.push_back(Point(560, 122));

	Solution s;
	int a = s.maxPoints(points);
	return 0;
}

//(29, 87), (145, 227), (400, 84), (800, 179), (60, 950), (560, 122), (-6, 5), (-87, -53), (-64, -118), (-204, -388), (720, 160), (-232, -228), (-72, -135), (-102, -163), (-68, -88), (-116, -95), (-34, -13), (170, 437), (40, 103), (0, -38), (-10, -7), (-36, -114), (238, 587), (-340, -140), (-7, 2), (36, 586), (60, 950), (-42, -597), (-4, -6), (0, 18), (36, 586), (18, 0), (-720, -182), (240, 46), (5, -6), (261, 367), (-203, -193), (240, 46), (400, 84), (72, 114), (0, 62), (-42, -597), (-170, -76), (-174, -158), (68, 212), (-480, -125), (5, -6), (0, -38), (174, 262), (34, 137), (-232, -187), (-232, -228), (232, 332), (-64, -118), (-240, -68), (272, 662), (-40, -67), (203, 158), (-203, -164), (272, 662), (56, 137), (4, -1), (-18, -233), (240, 46), (-3, 2), (640, 141), (-480, -125), (-29, 17), (-64, -118), (800, 179), (-56, -101), (36, 586), (-64, -118), (-87, -53), (-29, 17), (320, 65), (7, 5), (40, 103), (136, 362), (-320, -87), (-5, 5), (-340, -688), (-232, -228), (9, 1), (-27, -95), (7, -5), (58, 122), (48, 120), (8, 35), (-272, -538), (34, 137), (-800, -201), (-68, -88), (29, 87), (160, 27), (72, 171), (261, 367), (-56, -101), (-9, -2), (0, 52), (-6, -7), (170, 437), (-261, -210), (-48, -84), (-63, -171), (-24, -33), (-68, -88), (-204, -388), (40, 103), (34, 137), (-204, -388), (-400, -106)]
