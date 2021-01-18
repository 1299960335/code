#include"Heap.h"
void Printf(int *a,int b)
{
	for (int i = 0; i < b; i++) {
		printf("%d  ", a[i]);
	}
	printf("\n");
}
void TestTopk()//找出最大的5个数
{
	int a[] = { 12,52,8,98,1,25,36,87,45,69,12,33,10,28,30 };
	int n = sizeof(a) / sizeof(a[0]);
	int k = 5;
	PrintTopK(a, n, k);
}
int main() 
{
	int a[10] = {1,5,8,9,7,6,4,3,0,2};
	int b = sizeof(a) / sizeof(a[0]);
	//Heap hp;
	//HeapCreate(&hp, a, b);
	//HeapSort(a, b);
	//Printf(a, b);
	 TestTopk();
	return 0;
}