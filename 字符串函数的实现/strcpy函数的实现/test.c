#include<stdio.h>
#include<string.h>
void Cpy(char arr1[],char arr2[],int b)
{
	char* c = arr1;
	for (int i = 0; i < b; i++) {
		arr2[i] = *c;
		c++;
	}
	arr2[b] = '\0';
}
int main()
{
	char arr1[] = { "asdfgg" };
	char arr2[100];
	int b = strlen(arr1);
	Cpy(arr1, arr2, b);
	printf("%s\n", arr2);
	return 0;
}