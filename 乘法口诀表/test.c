#include <stdio.h>

void multiplication(int a) {

int b;

int c;

int d;

for (b = 1; b <= a;b++) {

for (c = 1; c <= b; c++) {

d = b * c;

printf("%d*%d=%d ", c, b, d);

}

printf("\n");

}

}

int main()

{

int a;

printf("你要打印几位的乘法口诀表：");

scanf_s("%d", &a);

multiplication(a);

return 0;

}