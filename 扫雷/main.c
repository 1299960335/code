#include"game.h"
int main()
{
	int quit = 0;
	int n;
	while (!quit) {
		Menu();
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			Game();
			printf("Ҫ��Ҫ����һ�֣�\n");
	
			break;
		case 2:
			quit = 1;
			printf("�ټ���");
			break;
		default:
			break;
		}
	}
	return 0;
}