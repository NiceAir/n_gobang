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
	 if(Pioneer==1)            //�������
	 {
		while(1)
		{
			Player_Do(board,level);
			Show_Board(board,level);
			sign=Judge_Win(board,level, num);
//			printf("sign=%c\n",sign);
			if(sign=='X')
			{
				printf("��ϲ�㣬��ʤ������\n");
				break;
			}
			else if(sign=='q')
			{
				printf("ƽ�֣�\n");
				break;
			}
			Computer_Do(board,level);
			Show_Board(board,level);
			sign=Judge_Win(board,level, num);
			if(sign=='O')
			{
				printf("���ź�������ʤ������\n");
				break;
			}
			else if(sign=='q')
			{
				printf("ƽ�֣�\n");
				break;
			}
		}
	 }

	 else									//��������
	 {

		 while(1)
		 {
			 Computer_Do(board,level);
			 Show_Board(board,level);
			 sign=Judge_Win(board,level, num);
//			 printf("sign=%c\n",sign);
			 if(sign=='O')
			 {
				 printf("��ϲ�㣬��ʤ������\n");
				 break;
			 }
			 else if(sign=='q')
			 {
				 printf("ƽ�֣�\n");
				 break;
			 }
			 Player_Do(board,level);
			 Show_Board(board,level);
			 sign=Judge_Win(board,level, num);
			 if(sign=='X')
			 {
				 printf("���ź�������ʤ������\n");
				 break;
			 }
			 else if(sign=='q')
			 {
				 printf("ƽ�֣�\n");
				 break;
			 }
		 }
	 }
	printf("********************************��Ϸ����****************************************\n");
	printf("*****�����ˣ�0********���¿�ʼ��1********�Ե�ǰ��������һ�֣�2***************\n");
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