#include<stdio.h>
int MAX(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int main()
{
	int a, b;
	printf("������������\n");
	scanf_s("%d %d", &a, &b);
	printf("%d\n", MAX(a, b));
	return 0;

}


