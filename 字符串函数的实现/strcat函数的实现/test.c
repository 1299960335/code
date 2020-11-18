#include<stdio.h>
void strca_t(char arr[],char arr1[],int b)
{
	char* s = arr;
	char* f = arr1;
	for (int i = 0; i < b; i++) {
		*s = *f;
		s++, f++;
	}
	printf("%s", arr);
}
int main()
{
	char arr[200] = { 0 };
	char arr1[100];
	fgets(arr1, sizeof(arr1)-1, stdin);
	int b=strlen(arr1);
	arr1[b - 1] = '\0';
	strca_t(arr, arr1,b);
	return 0;
}
