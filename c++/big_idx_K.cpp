#include <stdio.h>
#include <stdlib.h>
#define N 5

int a[N] = { 1, 2, 3, 4, 5 };
int b[N] = { 4, 5, 6, 7, 8 };

//获取数组a中从s1到n1个元素
//数组b中s2到n2个元素，合并后的第k大元素
int getMedian(int s1, int n1, int s2, int n2, int k) {
	//x和y分别记录中间值的索引
	int x, y;

	x = (s1 + n1) / 2;        //记录a的中位数索引
	y = (s2 + n2) / 2;        //记录b的中位数索引

	if (s1 > n1)
		return b[s2 + k - 1];
	if (s2 > n2)
		return a[s1 + k - 1];

	if (a[x] <= b[y]) {
		if (k <= (x - s1) + (y - s2) + 1) {
			return getMedian(s1, n1, s2, y - 1, k);
		}
		else {
			return getMedian(x + 1, n1, s2, n2, k - (x - s1) - 1);
		}
	}
	else {
		if (k <= (x - s1) + (y - s2) + 1) {
			return getMedian(s1, x - 1, s2, n2, k);
		}
		else {
			return getMedian(s1, n1, y + 1, n2, k - (y - s2) - 1);
		}
	}

	return 0;
}

int main() {
	int i;
	i = getMedian(0, 4, 0, 4, 5);
	printf("%d\n", i);
	return 0;
}