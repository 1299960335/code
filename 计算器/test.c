#include<stdio.h>
#define ERROR -1
int Add(int a,int b)
{
	return a + b;
}
int Sub(int a, int b)
{
	return a - b;
}
int Mul(int a, int b)
{
	return a * b;
}
int Div(int a, int b)
{
	if (b == 0) {
		printf("������Ϊ0��\n");
		return -1;
	}
		return a / b;
}
void Mune()
{
	printf("######################\n");
	printf("##1.Add     2.Sub#####\n");
	printf("##3.Mul     4.Div#####\n");
	printf("##    0.Exit    ######\n");
	printf("######################\n");
	printf("��ѡ��\n");

}
int main()
{
	int (*f[5])(int, int) = { NULL,Add,Sub,Mul,Div };
	int quit = 0;
	while (!quit) {
		Mune();
		int a = 0;
		scanf_s("%d", &a);
		if (a < 0 || a > 4) {
			printf("�����������������룡\n");
			continue;
		 }
		else if (a == 0) {
			break;
		}
		 printf("�������������ݣ�\n");
		 int b = 0;
		 int c = 0;
		scanf_s("%d %d", &b, &c);
		int ret = f[a](b, c);
		printf("%d\n", ret);
	}
	return 0;
}