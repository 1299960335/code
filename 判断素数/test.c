#include<stdio.h>

int prime_number(int a)

{

	for (int b = 2; b < a; b++) {

		if (a % b == 0) {

			return 0;

		}

	}

	return 1;

}

int main()

{

	int a;

	for (a = 100; a < 200; a++) {

		int c = prime_number(a);

		if (c == 1) {

			printf("%d ", a);

		}

	}

	return 0;

}

