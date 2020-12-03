#include<stdio.h>
#include<stdlib.h>
void Choice(int *a,int b)
{
	int c = 0;
	for (int i = 0; i < b; i++) { //循环找最大数
		c = i;
		for (int j = i + 1; j < b; j++) {//遍历数组，找出最大数的下标
			if (a[j] > a[c]) {//将最大数的下标进行交换
				c = j;
			}
		}
		if (c != i) {//将最大数放到前位
			int temp = a[i];
			a[i] = a[c];
			a[c] = temp;
		}
	}
	for (int k = 0; k < b; k++) {//打印数组
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