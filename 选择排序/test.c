#include<stdio.h>
#include<stdlib.h>
void Choice(int *a,int b)
{
	int c = 0;
	for (int i = 0; i < b; i++) { //ѭ���������
		c = i;
		for (int j = i + 1; j < b; j++) {//�������飬�ҳ���������±�
			if (a[j] > a[c]) {//����������±���н���
				c = j;
			}
		}
		if (c != i) {//��������ŵ�ǰλ
			int temp = a[i];
			a[i] = a[c];
			a[c] = temp;
		}
	}
	for (int k = 0; k < b; k++) {//��ӡ����
		printf("%d ", a[k]);
	}
}
int main()
{
	int arr[] = { 2,8,9,7,4,7,5,6 };
	int b = sizeof(arr) / sizeof(arr[0]);
	Choice(arr,b);
	return 0;
}