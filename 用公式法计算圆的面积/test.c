#include<stdio.h>
#include<math.h>
int main()
{
	double r;
	printf("请输出圆的半径：\n");
	scanf_s("%lf", &r);
	double n = 1;//用来计算需要循环增加的值
	double t,f,sum,k;
	double pi = 0.5;
	sum = 0.5;
	do {
		f = 1.0 / (2 * n + 1);//计算公式中间项
		t = pow(0.5, (2 * n + 1));//计算1/2的次方项
		if (n >= 2) {
			sum = sum * ((2 * n - 1) / (2 * n));//计算首项
		}
		k = f * t * sum;
		pi = pi + k;
		n++;
	} while ( k > 1e-10);//退出循环条件
	printf("圆的面积为：%lf\n", 6 * pi * r * r);
	return 0;
}