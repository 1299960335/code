#include"game.h"
void Menu() 
{
	printf("########################\n");
	printf("#### 1.play 2.end ######\n");
	printf("########################\n");
	printf("please select:");
}
void Showborad(char borad[][COL],int row,int col)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("[%c]",borad[i][j] );
		}
		printf("\n");
	}
}
void Playermove(char borad[][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1) {
		printf("请输入你的坐标!\n");
		scanf_s("%d %d", &x, &y);
		if (x < 1 || y < 1 || x > 3 || y > 3) {
			printf("输入有误!请重新输入\n");
			continue;
		}
		else if(borad[x-1][y-1]!=' '){
			printf("输入的地方有其他棋子，请重新输入!\n");
			continue;
		}
		else {
			borad[x - 1][y - 1] = P_er;
			break;
		}
	}
 }
Judge(char borad[][COL], int row, int col)
{
	for (int i = 0; i < row; i++) {
		if (borad[i][0] == borad[i][1] && \
			borad[i][1] == borad[i][2] && \
			borad[i][0] != ' ') {
			return borad[i][0];
		}
	}
	for (int j = 0; j < col; j++) {
		if (borad[0][j] == borad[1][j] && \
			borad[1][j] == borad[2][j] && \
			borad[0][j] != ' ') {
			return borad[0][j];
		}
	}
	if (borad[0][0] == borad[1][1] && \
		borad[1][1] == borad[2][2] && \
		borad[0][0] != ' ') {
		return borad[0][0];
	}
	if (borad[2][0] == borad[1][1] && \
		borad[1][1] == borad[0][2] && \
		borad[2][0] != ' ') {
		return borad[2][0];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (borad[i][j]==' ') {
				return NEXT;
			}
		}
	}
	return draw;
}



void  Computermove(char borad[][COL], int row, int col)
{
	while (1) {
		int x = rand() % row;
		int y = rand() % col;
		if (borad[x][y] == ' ') {
			borad[x][y] = Com_er;
			break;
		}
	}
}
 void  Game() 
{
	 srand((unsigned long)time(NULL));
	 char borad[ROW][COL];
	 memset(borad, ' ',sizeof(borad));
	 char result = 'x';
	 do {
		 Showborad(borad, ROW, COL);
		 Playermove(borad, ROW, COL);
		 result = Judge(borad, ROW, COL);
		 if (result != NEXT) {
			 break;
		 }
		 Computermove(borad, ROW, COL);
		 result = Judge(borad, ROW, COL);
		 if (result != NEXT) {
			 break;
		 }
	 } while (1);
	 if (P_er==result) {
		 printf("你赢了\n");
	 }
	 else if (Com_er == result) {
		 printf("你输了\n");
	 }
	 else {
		 printf("和棋\n");
	 }
	 
}