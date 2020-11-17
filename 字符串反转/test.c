#include<stdio.h>
#include<string.h>
void Cha_Z(char arr[],int a,int b)
{
	while (a) {
		char temp = arr[0];
		int i = 0;
		for (i = 0; i < b - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[i] = temp;
		a--;
	}
	printf("%s\n", arr);
}
int main()
{
	char arr[10] = { "ABCDE" };
	int a = 0;
	int b = strlen(arr);
	printf("你需要反转几次:");
	scanf_s("%d", &a);
	Cha_Z(arr,a,b);
	return 0;
}