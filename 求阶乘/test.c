#include<stdio.h>

int Factorial(int a)

{

int c=1;

while (a >= 2) {

c = c * a;

a--;

}

return c;

}

int main()

{

int a;

printf("请输入一个数：");

scanf_s("%d", &a);

Factorial(a);

printf("它的阶乘为：%d\n", Factorial(a));

return 0;

}