#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include"game.h"
#include "i.h"

void game() {
	int full = 0;
	int ret = 1;
	int temp = 0;
	//��Ϸ��ʼ ��Ϸ��ִ��
	//��ӡ���̡���������ά����
	char board[ROW][COL] = { 0 };
	//��ʼ�����̡�������Ԫ���ǿո�
	i(board, ROW, COL);
	//��ӡ����
	Display_board(board,ROW,COL);
	//�������ݣ��������
	do {
		playmover(board, ROW, COL);
		//��ӡ����
		Display_board(board, ROW, COL);
		//�ж�����Ƿ��ʤ
		ret=whether_win(board, ROW, COL);
		if (ret == '*')
		{
			printf("���ʤ��\n");
			break;

		}
		else if (ret == '#') {
			printf("����ʤ��");
			break;
		}
		else if (ret == 'c') {
			//������Ϸ
		}
		//�ж������Ƿ���--����ƽ�֣�û��ɶ��û��
		full=FULL(board,ROW,COL);
		if (full)
		{
			printf("ƽ��\n");
			break;
		}
		//�������ݣ���������
		computer(board, ROW, COL);
		//��ӡ����
		Display_board(board, ROW, COL);
		//�ж������Ƿ���--����ƽ�֣�û��ɶ��û��
		full = FULL(board, ROW, COL);
		if (full)
		{
			printf("ƽ��\n");
			break;
		}
		//�жϵ����Ƿ��ʤ
		ret = whether_win(board, ROW, COL);
		if (ret == '*')
		{
			printf("���ʤ��\n");
			break;

		}
		else if (ret == '#') {
			printf("����ʤ��");
			break;
		}
		else if (ret == 'c') {
			//������Ϸ
		}

	} while (ret);
}






void menu() {

	printf("#############################\n");
	printf("####1.��ʼ��Ϸ 0.������Ϸ####\n");
	printf("#############################\n");

}
//���������
//һ����Ϸһ��ȥҪ����Ϸ����ѡ���Ƿ������Ϸ
#include<stdio.h>
int main() {
int input = 0;
srand((unsigned int)time(NULL));
	do {
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input) {
		case 0:
			printf("�������");
			break;
		case 1:
			game();
			break;
		default:
			printf("�����������������");
				break;
		}
	} while (input);
	return 0;
}