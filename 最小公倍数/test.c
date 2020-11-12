#include<stdio.h>
void Str(int a, int b)
{
	for (int i = 1; i <= (a * b); i++) {
		if (((i % a) == 0) && ((i % b) == 0)){
			printf("%d", i);
			break;
        }
	}
}
int main() 
{ 
	int a = 0;
	int b = 0;
	scanf_s("%d %d", &a, &b);
	Str(a, b);
	return 0;
}