#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define COL 10
#define ROW 10
void i(char borad[ROW][COL], int row, int col);
void Display_board(char board[ROW][COL], int row, int col);
void playmover(char board[ROW][COL], int row, int col);
void computer(char board[ROW][COL], int row, int col);
int whether_win(char board[ROW][COL],int row, int col);
int FULL(char board[ROW][COL], int row, int col);

