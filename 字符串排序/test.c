#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
void Swap(char* a, char* b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
int main()
{
	char arr[30] = { '\0' };
	scanf("%s", arr);
	int l = strlen(arr);
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
	printf("%s", arr);
	return 0;
}