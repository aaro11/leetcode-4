#include <stdio.h>
#include <stdlib.h>
#define N 5

int a[N] = { 1, 2, 3, 4, 5 };
int b[N] = { 4, 5, 6, 7, 8 };

//��ȡ����a�д�s1��n1��Ԫ��
//����b��s2��n2��Ԫ�أ��ϲ���ĵ�k��Ԫ��
int getMedian(int s1, int n1, int s2, int n2, int k) {
	//x��y�ֱ��¼�м�ֵ������
	int x, y;

	x = (s1 + n1) / 2;        //��¼a����λ������
	y = (s2 + n2) / 2;        //��¼b����λ������

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