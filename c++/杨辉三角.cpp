
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> res;
		for (size_t i = 0; i < numRows; i++)
		{
			vector<int> tmp;
			for (size_t j = 0; j <= i; j++)
			{
				if ((j == 0) || (j == i))
				{
					tmp.push_back(1);
				}
				else
				{

				}
				//a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
				//int tmp = a[i - 1][j] + a[i - 1][j - 1];
				//int hh = res[i];
				tmp.push_back(j);
				//cout << j+1;
			}

			res.push_back(tmp);

			//cout << endl;
		}	

		return res;
	}
};

int main()
{
	Solution s;

	vector<vector<int>> = s.generate(5);

	return 0;
}

//int main()
//{
//	int a[10][10] = {0};
//	int i, j;
//	for (i = 0; i<10; i++)
//	{
//		a[i][0] = 1; a[i][i] = 1;
//	}
//	for (i = 2; i<10; i++)
//	{
//		for (j = 1; j<i; j++)
//			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
//	}
//	for (i = 0; i<10; i++)
//	{
//		for (j = 0; j <= i; j++)
//			printf("%d", a[i][j]);
//		printf("\n");
//	}
//	return 0;
//}