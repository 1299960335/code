#include<stdio.h>
#include<assert.h>
#include<string.h>
void* my_memove(void* arr, const void* arr1,int num)
{
	assert(arr);
	assert(arr1);
	char* a = (char*)arr;
	const char* b = (const char*)arr1;
	if (a > b && a < b + num) {
		a = a + num - 1;
		b = b + num - 1;
		while (num) {
			*a = *b;
			a--, b--;
			num--;
		}
	}
	else {
		while (num) {
			*a = *b;
			a++, b++;
			num--;
		}
	}
	return arr;
}
int main()
{
	char arr[16] = "abcd1234";
	my_memove(arr + 1, arr, strlen(arr) + 1);
	printf("%s\n", arr);
	return 0;	
}