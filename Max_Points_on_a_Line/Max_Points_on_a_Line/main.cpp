
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
