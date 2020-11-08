#include"game.h"
void Menu()
{
	printf("###########################\n");
	printf("##  1.PLAY    2.EXIT   ####\n");
	printf("###########################\n");
	printf("请输入你的选择:");
}
void SetMines(char mine_broad[][COL], int row, int col)
{
	int count = NUMS;
	while (count) {
		int x = rand() % 10 + 1;
		int y = rand() % 10 + 1;
		if (mine_broad[x][y] == '0') {
			mine_broad[x][y] = '1';
			count--;
		}
	}
}
int GetMines(char mine[][COL], int row, int col, int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] + \
		mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1] + \
		mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';
}
void ShowLine(int nums)
{
	printf("---");
	for (int i = 0; i < nums; i++) {
		printf("-");
	}
	printf("\n");
}

void Show_broad(char show_broad[][COL], int row, int col)
{
	printf("   ");
	for (int i = 1; i < row - 1; i++) {
		printf(" %d  ", i);
	}
	printf("\n");
	ShowLine(2 * col + col + 4);

	for (int i = 1; i < row - 1; i++) {
		printf("%2d|", i);
		for (int j = 1; j < col - 1; j++) {
			printf(" %c |", show_broad[i][j]);
		}
		printf("\n");
		ShowLine(2 * col + col + 4);
	}
}

void Game()
{
	char show_broad[ROW][COL];
	char mine_broad[ROW][COL];
	memset(show_broad, '*', sizeof(show_broad));
	memset(mine_broad, '0', sizeof(mine_broad));
	srand((unsigned long)time(NULL));

	SetMines(mine_broad, ROW, COL);
	int count = (ROW - 2) * (COL - 2) - NUMS;
	int x = 0;
	int y = 0;
	do {
		Show_broad(show_broad, ROW, COL);
		printf("请输入位置# ");
		scanf_s("%d %d", &x, &y);
		if (x < 1 || x > 10 || y < 1 || y >10) {
			printf("输入越界，请重新输入!\n");
			continue;
		}
		if (show_broad[x][y] != '*') {
			printf("该位置已经被排除，请重新输入!\n");
			continue;
		}
		if (mine_broad[x][y] == '1') {
			break;
		}
		int num = GetMines(mine_broad, ROW, COL, x, y);
		show_broad[x][y] = num + '0';
		count--;
		system("cls");
	} while (count > 0);
	if (count > 0) {
		printf("你被炸死了！");
	}
	else {
		printf("你赢了！\n");
	}
	printf("下面是雷区的排布\n");
	Show_broad(mine_broad, ROW, COL);
}
