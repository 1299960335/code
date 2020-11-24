#include<stdio.h>
#include<stdlib.h>
int CompInt(const void* _xp, const void* _yp)
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
void print(int arr[], int num)
{
	for (int i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int CompStr(const void* _xp, const void* _yp)
{
	char* s1 = *(char**)_xp;
	char* s2 = *(char**)_yp;
	return strcmp(s1, s2);
}
int main()
{
	char* arr[] = { "adwef,14asdw,wfg57,siw854,14sdw" };
	//int arr[] = { 147,25,912,81,814,3841,47,23,88,1,52,3 };
	int num = sizeof(arr) / sizeof(arr[0]);
	//print(arr,num);
	qsort(arr, num, sizeof(char*), CompStr);
	//print(arr, num);
	printf("%s", *arr);
	return 0;
}