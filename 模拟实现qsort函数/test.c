#include<stdio.h>
#include<assert.h>
int CompInt(const void* _xq, const void* _yq)  //实现数组元素的比较
{
	int* xq = (int*)_xq;
	int* yq = (int*)_yq;
	if (*xq > * yq) {
		return 1;
	}
	else if (*xq < *yq) {
		return -1;
	}
	else {
		return 0;
	}
}
void swup(char* srt, char* est, int size)//进行冒泡排序
{
	while (size) {
		char temp = *srt;
		*srt = *est;
		*est = temp;
		srt++;
		est++;
		size--;
	}
}
void print( int arr[] ,int size)//打印数组
{
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void my_qsort(void* arr,int set, int size, int(*comp)(const void*,const void*))//qsort函数的实现
{
	assert(arr != NULL);//判断指针是否合法
	assert(comp != NULL);
	char* e = (char*)arr;
	for (int i = 0; i < set - 1; i++) {
		int flag = 0;
		for (int j = 0; j < set - 1 - i; j++) {
			if (comp(e + j*size ,e + (j+1)*size) > 0) {   //访问各个字节进行交换排序
					flag = 1;
					swup(e + j * size, e + (j + 1) * size,size);
			}
		}
		if (flag == 0) {   //如果元素有序，则推出循环
				break;
		}
	}
}
int main()
{
	int arr[] = { 12,57,84,94,15,645,123,47 };
	int set = sizeof(arr) / sizeof(arr[0]);
	print(arr, set);
	my_qsort(arr,set,sizeof(int),CompInt);
	print(arr, set);
	return 0;
}