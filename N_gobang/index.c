#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "game.h"
int x=0, y=0;
int main(){
	int level=0, num=0, Pioneer=0;
	char sign='\0';
	char board[ROW][COL];
	int again=0;
	int c=0;
	srand((unsigned int)time(NULL));
AGAIN1:	Creat_Rule(&level, &num, &Pioneer);
AGAIN2:	 Init_Board(board,level);
	 Show_Board(board,level);
	 if(Pioneer==1)            //玩家先走
	 {
		while(1)
		{
			Player_Do(board,level);
			Show_Board(board,level);
			sign=Judge_Win(board,level, num);
//			printf("sign=%c\n",sign);
			if(sign=='X')
			{
				printf("恭喜你，获胜！！！\n");
				break;
			}
			else if(sign=='q')
			{
				printf("平局！\n");
				break;
			}
			Computer_Do(board,level);
			Show_Board(board,level);
			sign=Judge_Win(board,level, num);
			if(sign=='O')
			{
				printf("很遗憾，电脑胜！！！\n");
				break;
			}
			else if(sign=='q')
			{
				printf("平局！\n");
				break;
			}
		}
	 }

	 else									//电脑先走
	 {

		 while(1)
		 {
			 Computer_Do(board,level);
			 Show_Board(board,level);
			 sign=Judge_Win(board,level, num);
//			 printf("sign=%c\n",sign);
			 if(sign=='O')
			 {
				 printf("恭喜你，获胜！！！\n");
				 break;
			 }
			 else if(sign=='q')
			 {
				 printf("平局！\n");
				 break;
			 }
			 Player_Do(board,level);
			 Show_Board(board,level);
			 sign=Judge_Win(board,level, num);
			 if(sign=='X')
			 {
				 printf("很遗憾，电脑胜！！！\n");
				 break;
			 }
			 else if(sign=='q')
			 {
				 printf("平局！\n");
				 break;
			 }
		 }
	 }
	printf("********************************游戏结束****************************************\n");
	printf("*****不玩了：0********重新开始：1********以当前规则再玩一局：2***************\n");
	scanf("%d", &again);
	while((c = getchar()) != '\n' && c != EOF);
//	if(again!=0) (again==1) ? ( goto AGAIN1) : (goto AGAIN2);
	switch (again)
	{
	case 1: goto AGAIN1; break;
	case 2: goto AGAIN2; break;
	default: return 0;
	}
	return 0;
}