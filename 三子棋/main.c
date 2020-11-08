#include"game.h"
int main()
{
	int quit = 0;
	int select = 0;
	while (!quit) {
		Menu();
		scanf_s("%d",&select);
		switch (select) {
		case 1:
			Game();
			printf("再来一局?\n");
			break;
		case 2:
			quit = 1;
			break;
		default:
			printf("输入有误,请重新输入!\n");
			break;
		}
	}
	printf("bye bye!");
	return 0;
}