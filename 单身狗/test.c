#include<stdio.h>
#include<stdlib.h>
int CompInt(const void*_xp,const void*_yp) //�ȽϺ���
{
	int* xp = (int*)_xp;
	int* yp = (int*)_yp;
	if (*xp > * yp) {
		return 1;
	}
	else if (*xp < *yp) {
		return -1;
	}
	else {
		return 0;
	}
}
void Single(int arr[])
{
	int a = 10;
	for (int i = 0; i < 9; i++) { //���ǰһ�����һ��ֵ��ȣ������ʼ��Ϊ0
		if (arr[i] == arr[i + 1]) {//������������
			arr[i] = 0;
			arr[i + 1] = 0;
		}
	}
	for (int j = 0; j < 10; j++) {//��ӡɸѡ������Ԫ�أ���Щ���ǵ���Ԫ��
		if (arr[j] != 0) {
			printf("%d ",arr[j]);
		}
	}
}
int main()
{
	int arr[10] = {1,2,3,4,5,6,1,2,3,4 };
	qsort(arr, 10, sizeof(int),CompInt);//�������������
	Single(arr);
	return 0;
}