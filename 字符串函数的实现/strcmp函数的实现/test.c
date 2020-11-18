#include<stdio.h>
#include<string.h>
int Cmp(char arr1[], char arr2[], int a, int b)
{
	if (a > b) {
		return 1;
	}
	else if (a < b) {
		return -1;
	}
	else {
		char* c = arr1;
		char* d = arr2;
		int e = 0;
		for (int i = 0; i < a; i++) {
			if (*c == *d) {
				c++, d++;
			}
			else {
				e = 1;
				break;
			}	
		}
		if (e != 1) {
			return 0;
		}
		else {
			return 1;
		}
	}
}
int main()
{
	char arr1[] = { "asdfg" };
	char arr2[] = { "sffxc" };
	int a = strlen(arr1);
	int b = strlen(arr2);
	printf("%d", Cmp(arr1, arr2, a, b));
	return 0;
}