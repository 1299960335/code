#include<stdio.h>
#include<math.h>
int main()
{
	double r;
	printf("�����Բ�İ뾶��\n");
	scanf_s("%lf", &r);
	double n = 1;//����������Ҫѭ�����ӵ�ֵ
	double t,f,sum,k;
	double pi = 0.5;
	sum = 0.5;
	do {
		f = 1.0 / (2 * n + 1);//���㹫ʽ�м���
		t = pow(0.5, (2 * n + 1));//����1/2�Ĵη���
		if (n >= 2) {
			sum = sum * ((2 * n - 1) / (2 * n));//��������
		}
		k = f * t * sum;
		pi = pi + k;
		n++;
	} while ( k > 1e-10);//�˳�ѭ������
	printf("Բ�����Ϊ��%lf\n", 6 * pi * r * r);
	return 0;
}