#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
#include "i.h"
//平局
int  FULL(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++) 
	{
		int j = 0;
		for (j=0;j<col;j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;

}

//输赢
//原码
//int whether_win(char board[ROW][COL], int row, int col) {
//	//列胜利
//	for (int i = 0; i < ROW; i++)
//	{
//		//player win-----'*'
//		//computer win---'#'
//		//平局-----'q'
//		//继续游戏----'c'
//		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
//		{
//			return board[0][i];
//			break;
//		}
//	}
//	//行胜利
//	for (int i = 0; i < COL; i++)
//	{
//		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
//		{
//			return board[i][0];
//		}
//	}
//
//
//
//	//对角线胜利
//	if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[0][0] != ' ')
//	{
//		return board[0][0];
//	}
//	if (board[0][3] == board[1][1] && board[3][1] == board[1][1] && board[0][3] != ' ')
//	{
//		return board[0][0];
//	}
//	return 'c';
//
//
//}
//

 //优化
int whether_win(char board[ROW][COL], int row, int col) {
	//列胜利
	for (int i = 0; i <col; i++)
	{
		int j = 0;
		//player win-----'*'
		//computer win---'#'
		//平局-----'q'
		//继续游戏----'c'
		for (int j = 0; j < col; j++)
		{
			if (board[j][i] == board[j+1][i]&& board[j+1][i] == board[j+2][i] && board[j+2][i]==board[j+3][i]&&board[j+3][i]==board[j+4][i]&&board[j][i] != ' ')
			{
				return board[i][j];
			}
		}
	}
	//行胜利
	for (int i = 0; i < row; i++)
	{

		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2]&&board[i][j+2]==board[i][j+3]&&board[i][j+3]==board[i][j+4] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}

	}

	//对角线胜利
	for (int i = 0; i <row; i++)
	{
		for (int j = 0; j < col; j++)
		{

			if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i + 2][j + 2] == board[i + 3][j + 3] && board[i + 3][j + 3] == board[i + 4][j + 4] && board[i][j] != ' ')
			{
				return board[i][j];
			}
			if (board[i][j] == board[i+1][j-1] && board[i+1][j-1] == board[i+2][j-2] && board[i + 2][j - 2] == board[i + 3][j - 3] && board[i + 3][j - 3] == board[i + 4][j - 4] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}



		return 'c';

	
}


















void computer(char board[ROW][COL], int row, int col) {
	printf("电脑走\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		
		x = rand()%ROW;
		y = rand()%COL;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}

}












void playmover(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	
	while (1)
	{printf("玩家走:>\n");
	 scanf("%d%d", &x, &y);
	 if (x>=1&&x <=row&& y>=1&&y <= col)
	 {

	if (board[x - 1][y - 1] == ' ')
		{
		board[x-1][y-1] = '*';
			break;
		}
	else 
	{
		printf("该坐标已被占用，请重新输入");
	}
	 }
	 else {
		 printf("该坐标错误，请重新输入");
	 }


	
	}






}














void i(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			board[i][j] = ' ';
	};



}


void Display_board(char board[ROW][COL], int row, int col) {

	for (int i = 0; i < row; i++)//打印行
	{
		/*borad_arr[row][col];*/
		for (int j = 0; j < col; j++)//打印列
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");

		}
		printf("\n");
		//打印分割行
		if (i < row - 1) 
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}

	}
}
