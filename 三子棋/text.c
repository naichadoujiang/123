#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include"game.h"
#include "i.h"

void game() {
	int full = 0;
	int ret = 1;
	int temp = 0;
	//游戏开始 游戏的执行
	//打印棋盘————二维数组
	char board[ROW][COL] = { 0 };
	//初始化棋盘。将棋盘元素是空格
	i(board, ROW, COL);
	//打印棋盘
	Display_board(board,ROW,COL);
	//输入数据，玩家输入
	do {
		playmover(board, ROW, COL);
		//打印棋盘
		Display_board(board, ROW, COL);
		//判断玩家是否获胜
		ret=whether_win(board, ROW, COL);
		if (ret == '*')
		{
			printf("玩家胜利\n");
			break;

		}
		else if (ret == '#') {
			printf("电脑胜利");
			break;
		}
		else if (ret == 'c') {
			//继续游戏
		}
		//判断棋盘是否满--满了平局，没满啥事没有
		full=FULL(board,ROW,COL);
		if (full)
		{
			printf("平局\n");
			break;
		}
		//输入数据，电脑输入
		computer(board, ROW, COL);
		//打印棋盘
		Display_board(board, ROW, COL);
		//判断棋盘是否满--满了平局，没满啥事没有
		full = FULL(board, ROW, COL);
		if (full)
		{
			printf("平局\n");
			break;
		}
		//判断电脑是否获胜
		ret = whether_win(board, ROW, COL);
		if (ret == '*')
		{
			printf("玩家胜利\n");
			break;

		}
		else if (ret == '#') {
			printf("电脑胜利");
			break;
		}
		else if (ret == 'c') {
			//继续游戏
		}

	} while (ret);
}






void menu() {

	printf("#############################\n");
	printf("####1.开始游戏 0.结束游戏####\n");
	printf("#############################\n");

}
//三子棋测试
//一个游戏一进去要有游戏界面选择是否进入游戏
#include<stdio.h>
int main() {
int input = 0;
srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input) {
		case 0:
			printf("程序结束");
			break;
		case 1:
			game();
			break;
		default:
			printf("输入错误请重新输入");
				break;
		}
	} while (input);
	return 0;
}