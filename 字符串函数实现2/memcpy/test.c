#include<stdio.h>
#include<assert.h>
void* my_memcpy(void* arr, const void* arr1, int num)
{
	assert(arr);
	assert(arr1);
	char* a = (char*)arr;
	const char* b = (const char*)arr1;
	while (num) {
		*a = *b;
		a++, b++;
		num--;
	}
	return arr;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6 };
	int arr1[10] = { 0 };
	my_memcpy(arr1, arr, sizeof(arr));
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr1[i]);
	}
	return 0;
}