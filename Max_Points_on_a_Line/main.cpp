
#include <vector>
#include <map>
using namespace std;

//Definition for a point.
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

//map<int, string> mapStudent;
//mapStudent.insert(pair<int, string>(1, "student_one "));
//mapStudent.insert(pair<int, string>(2, "student_two "));
//mapStudent.insert(pair<int, string>(3, "student_three "));
//map<int, string>::iterator iter;
//iter = mapStudent.find(1);
//if (iter != mapStudent.end())
//{
//	cout << "Find, the value is: " << iter->second << endl;
//}
//else
//{
//	cout << "Do not Find" << endl;
//}
//return 0;



class Solution
{
private:


public:
	int maxPoints(vector<Point> &points)
	{
		map<double, int> slopes;
		int count = 0;

		int len = points.size();
		if (len == 1)
			return 1;
		for (int i = 0; i<len; i++)
		{
			int max = 0;
			slopes.clear();
			map<double, int>::iterator iter;
			int sameCount = 0;
			for (int j = i + 1; j<len; j++)
			{
				if ((points[i].x == points[j].x) && (points[i].y == points[j].y))
				{
					sameCount++;
					continue;
				}
					
				//求其他点与这条直线的斜率
				double slope = (points[i].x - points[j].x == 0) ? 0 : (points[i].y - points[j].y + 0.0) / (points[i].x - points[j].x);
				iter = slopes.find(slope);
				if (iter == slopes.end())
				{
					slopes[slope] = 2;
				}
				else
				{
					slopes[slope]++;
				}
			}
			//遍历map求里面值最大的
			for (iter = slopes.begin(); iter != slopes.end(); iter++)
			{
				if (max < (iter->second + sameCount))
				{
					max = iter->second + sameCount;
				}
			}
			
			if (max < sameCount + 1)
				max = sameCount + 1;

			if (count < max)
			{
				count = max;
			}
		}
		return count;
	}
};

int main()
{
	vector<Point> points;
	points.push_back(Point(0, 0));
	points.push_back(Point(0, 0));

	Solution s;
	int a = s.maxPoints(points);
	return 0;
}
