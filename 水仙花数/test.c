#include<stdio.h>
int Num(int i)
{
	int count = 0;
	while (i > 0) {
		count++;
		i /= 10;
	}
	return count;
}
int Is_shuixianhua(int i, int num)
{
	int sum = 0;
	int j = 0;
	int m = i;
	int n = 1;
	while (m > 0) {
		int temp = m % 10;
		m /= 10;
		for (j = num; j > 0; j--) {
			n *= temp;
		}
		sum += n;
		n = 1;
	}
	if (sum == i) {
		return 1;
	}
	else {
		return 0;
	}
}
int main()
{
	int i = 0;
	for (i = 0; i < 100000; i++) {
		int num = Num(i);
		if (Is_shuixianhua(i, num)) {
			printf("%d\n", i);
		}
	}
	return 0;
}





















//void Str(int arr[], int b)
//{
//	char arr2[13] = "             ";
//	int mid = b / 2;
//	int* c = arr;
//	int i = mid;
//	int left = mid - 1;
//	int rigt = mid + 1;
//	while (i > 0) {
//		for (int i = 0; i < 13; i++) {
//			arr2[mid] = *c;
//			printf("%c", arr2[i]);
//		}
//		printf("\n");
//		arr2[left] = *c;	QA
//		arr2[rigt] = *c;
//		left--;
//		rigt++;
//		i--;
//	}
//}
//void Str2(int arr[], int b)
//{
//	char arr2[13] = "             ";
//	int mid = b / 2;
//	int* c = arr2;
//	int i = mid;
//	int left =0;
//	int rigt =b-1;
//	while (i >= 0) {
//		for (int i = 0; i < 13; i++) {
//			printf("%c", arr[i]);
//		}
//		printf("\n");
//		arr[left] = *c;
//		arr[rigt] = *c;
//		rigt--;
//		left++;
//		i--;
//	}
//}
//int main()
//{
//	int arr[13];
//	for (int i = 0; i < 13; i++) {
//		arr[i] = '*';
//	}
//	int b = sizeof(arr) / sizeof(arr[0]);
//	Str(arr,b);
//	Str2(arr,b);
//	return 0;
//}








//int main()
//{
//	int a = 0;
//	int* b = NULL;
//	int c = 0;
//	int d = 0;
//	int Sn = 0;
//	printf("请输入一个数：\n");
//	scanf_s("%d", &a);
//	printf("你需要几项之和：");
//	scanf_s("%d", &c);
//	b = &a;
//	d = a;
//	while (c>0) {
//		Sn = *b+Sn;
//		*b = (*b * 10) + d;
//		c--;
//	}
//	printf("%d", Sn);
//	return 0;
//}
//






//void Str(char a[],int b)
//{
//	char* c = a;
//	for (int i = b; i >= 0;i--) {
//		printf("%c", *(c+i));
//	}
//}
//
//int main()
//{
//	char a[] = "123456";
//	int b = sizeof(a) / sizeof(a[0]);
//	Str(a,b);
//	return 0;
//}







//void Str(int arr[])
//{
//	int* a = arr;
//	for (int i = 0; i < 10; i++) {
//		printf("%d ", *a);
//		a += 1;
//	}
//}
//int main()
//{
//	int arr[10];
//	for (int i = 0; i < 10; i++) {
//		arr[i] = i;
//	}
//	Str(arr);
//	return 0;
//}