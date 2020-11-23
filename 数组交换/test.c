#include<stdio.h>

int main()

{

	int c = 0;

	int arr1[10] = { 0,1,2,3,4,5,6,7,8,9 };

	int arr2[10] = { 9,8,7,6,5,4,3,2,1,0 };

	int arr3[10] = { 0 };

	for (int a = 0; a < 10; a++) {

		arr3[a] = arr1[a];

		arr1[a] = arr2[a];

		arr2[a] = arr3[a];

		printf("%d ", arr1[a]);

	}

	printf("\n");

	for (int b = 0; b < 10; b++) {

		printf("%d ", arr2[b]);

	}

	return 0;

}