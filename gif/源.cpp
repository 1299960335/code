#include<stdio.h>
#include<string.h>
#include<windows.h>
 
int start = 0;
int end = 0;
int i;
void show()
{

}
int main()
{
	char arr1[] = "|/-\\";
	char arr2[] = "";
	while (1) {
		arr2[0] = arr1[i++%4];
	printf("%c.\r", arr2[0]);
		Sleep(100);
		
	 }
	printf("\n");
}