#include<stdio.h>
#define H 10       //��Ҫ��ӡ������
void Yang_hui(int arr[], int b)
{   
	int a = 1;
	int c = b - 1;//���鳤��-1��
	arr[0] = a;
	for (int i = 0; i < b; i++) {   //��ӡ��һ������
		if (arr[i] < 1) {          //ȥ��ԭ�����ʼ����ֵ
			break;
		}
		printf("%d ", arr[i]);
	}
	printf("\n");
	while (c > 0) {
		for (int i = 9; i > 0; i--) {  //�����������
			if (i <= 9&&i!=0 ) {
				arr[i] = arr[i] + arr[i - 1];
			}
		}
		for (int j = 0; j < 10; j++) {  //ÿ����һ�δ�ӡһ������
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