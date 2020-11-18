#include<stdio.h>
int Str(char arr[])
{
	char* a = arr;
	int b = 0;
	while (1) {
		if (*a == '\0') {
			return b;
			break;
		}
		a++;
		b++;
	}
}
int main()
{
	char arr[] = { "asdfgag" };
	printf("%d ",Str(arr));
	return 0;
}