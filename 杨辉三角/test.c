#include<stdio.h>
#define H 10       //需要打印的行数
void Yang_hui(int arr[], int b)
{   
	int a = 1;
	int c = b - 1;//数组长度-1；
	arr[0] = a;
	for (int i = 0; i < b; i++) {   //打印第一行数组
		if (arr[i] < 1) {          //去除原数组初始化的值
			break;
		}
		printf("%d ", arr[i]);
	}
	printf("\n");
	while (c > 0) {
		for (int i = 9; i > 0; i--) {  //计算杨辉三角
			if (i <= 9&&i!=0 ) {
				arr[i] = arr[i] + arr[i - 1];
			}
		}
		for (int j = 0; j < 10; j++) {  //每计算一次打印一次数组
			if (arr[j] < 1) {
				break;
			}
			printf("%d ", arr[j]);
		}
		printf("\n");
		c--;
	}
}

int main()
{
	int arr[H] = {0};
	int b = sizeof(arr) / sizeof(arr[0]);
	Yang_hui(arr,b);
	return 0;
}