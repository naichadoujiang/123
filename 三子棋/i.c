#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
#include "i.h"
//ƽ��
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

//��Ӯ
//ԭ��
//int whether_win(char board[ROW][COL], int row, int col) {
//	//��ʤ��
//	for (int i = 0; i < ROW; i++)
//	{
//		//player win-----'*'
//		//computer win---'#'
//		//ƽ��-----'q'
//		//������Ϸ----'c'
//		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
//		{
//			return board[0][i];
//			break;
//		}
//	}
//	//��ʤ��
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
//	//�Խ���ʤ��
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

 //�Ż�
int whether_win(char board[ROW][COL], int row, int col) {
	//��ʤ��
	for (int i = 0; i <col; i++)
	{
		int j = 0;
		//player win-----'*'
		//computer win---'#'
		//ƽ��-----'q'
		//������Ϸ----'c'
		for (int j = 0; j < col; j++)
		{
			if (board[j][i] == board[j+1][i]&& board[j+1][i] == board[j+2][i] && board[j+2][i]==board[j+3][i]&&board[j+3][i]==board[j+4][i]&&board[j][i] != ' ')
			{
				return board[i][j];
			}
		}
	}
	//��ʤ��
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

	//�Խ���ʤ��
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
	printf("������\n");
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
	{printf("�����:>\n");
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
		printf("�������ѱ�ռ�ã�����������");
	}
	 }
	 else {
		 printf("�������������������");
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

	for (int i = 0; i < row; i++)//��ӡ��
	{
		/*borad_arr[row][col];*/
		for (int j = 0; j < col; j++)//��ӡ��
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");

		}
		printf("\n");
		//��ӡ�ָ���
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
