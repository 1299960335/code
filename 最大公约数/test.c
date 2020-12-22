#include<stdio.h>

int com(int a,int b,int t)

{

int s = 0;

while (t >1){

if (a % t == 0 && b % t == 0) {

s = t;

break;

}

t--;

}

return s;

}

int main()

{

int a = 0;

int b = 0;

int t = 0;

scanf_s("%d,%d",&a,&b);

if (a < b) {

t = a;

}

else

t = b;

int s = com(a,b,t);

printf("%d\n", s );

return 0;



}