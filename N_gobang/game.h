#ifndef __GAME_H__
#define __GAME_H__
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#define  ROW 36
#define COL 36
extern int x, y;
void Creat_Rule(int *level, int *num, int *Pioneer);
void Init_Board(char board[ROW][COL], int level);
void Show_Board(char board[ROW][COL], int level);
void Player_Do(char board[ROW][COL], int level);
void Computer_Do(char board[ROW][COL], int level);
char Judge_Win(char board[ROW][COL], int level, int num);
#endif