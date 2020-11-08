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
			printf("要不要再来一局？\n");
	
			break;
		case 2:
			quit = 1;
			printf("再见！");
			break;
		default:
			break;
		}
	}
	return 0;
}