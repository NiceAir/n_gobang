#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

extern int x, y;
void Creat_Rule(int *level, int *num, int *Pioneer){
	int c=0;
	char affirm[5]={'\0'};
Loop:
		printf("请选择棋盘大小（3阶到36阶）>");
		while(scanf("%d", level))
		{
			int c=0;
			while((c = getchar()) != '\n' && c != EOF);     //清除键盘缓冲区的万能写法

			if(*level<3) printf("输入错误，请重新指定\n");
			else
			{
				break;
			}	
		}
		printf("您想玩几子连珠？（不得小于3）>");
		while(scanf("%d", num))
		{
			int c=0;
			while((c = getchar()) != '\n' && c != EOF);     //清除键盘缓冲区的万能写法
			if(*num<3) printf("输入错误，请重新输入\n");
			else if(*num>*level)
			{
				printf("超过了棋盘的范围，请重新输入\n");
			}
			else
			{
				break;
			}
		}
		printf("您和电脑谁先走？（若你先走，输入1；若电脑先走，输入2）>");
		while(scanf("%d", Pioneer))
		{
			int c=0;
			while((c = getchar()) != '\n' && c != EOF);     //清除键盘缓冲区的万能写法
			if(*Pioneer!=1 && *Pioneer!=2) printf("输入错误，请重新输入\n");
			else
			{
				break;
			}
		}
		printf("请确认规则：\n");
		if(*Pioneer==1) printf("您定制的规则为： 在一个%d*%d的棋盘上，谁先将%d颗棋子连成一条线谁就赢了，您先走\n", *level, *level, *num);
		else  printf("您定制的规则为： 在一个%d*%d的棋盘上，谁先将%d颗棋子连成一条线谁就赢了，电脑先走\n", *level, *level, *num);
		printf("****************确认并开始游戏？(Y/N)>");
		scanf("%s", affirm);

		while((c = getchar()) != '\n' && c != EOF);     //清除键盘缓冲区的万能写法
		if( !(strcmp(affirm, "Y")==0 || strcmp(affirm, "y")==0 || strcmp(affirm, "YES")==0 || strcmp(affirm, "yes")==0 || strcmp(affirm, "Yes")==0 ) )  goto Loop; 
}

void Init_Board(char board[ROW][COL], int level){
	int i=0, j=0;
	/*board=(char **)malloc(sizeof(char *)*level);
	for (i=0; i<level; i++)
	{
		board[i]=(char *)malloc(sizeof(char *)*level);
	}*/
	for(i=0; i<level; i++)
	{
		for(j=0; j<level; j++)
		{
			board[i][j]=' ';
		}
	}
}
void Show_Board(char board[ROW][COL], int level){
	int i = 0, j = 0;
	for(i=0; i<level; i++)
	{

			for(j=0; j<level; j++)
			{
				printf(" ---");
			}
			printf("\n");
			for (j=0; j<level; j++)
			{
				printf("| %c ",board[i][j]);
			}

			printf("|\n");
		if(i==level-1)
		{
			for(j=0; j<level; j++)
			{
				printf(" ---");
			}
		}
	}
	printf("\n");
}


int Judge_Legal(char board[ROW][COL], int level, int x, int y){
	if(x>=level || y>=level || x<0 || y<0) return 1;
	if(board[x][y]!=' ') return 2;
	return 0;
}




void Player_Do(char board[ROW][COL], int level){
	int c=0;
	int a=0, b=0;
	printf("Tips: 左上角为（1,1），右下角为（%d，%d）\n", level, level);
	printf("玩家走>");
	while(scanf("%d%d", &a,&b))
	{
		int c=0;
		while((c = getchar()) != '\n' && c != EOF);     //清除键盘缓冲区的万能写法
		x=a-1;
		y=b-1;
		if(Judge_Legal(board, level, x, y)==0)
		{
			board[x][y]='X';
			break;
		}
		else if(Judge_Legal(board, level, x, y)==1)
		{
			printf("您输入的位置不合法，请重新输入>");
		}
		else printf("这里已经有棋子了，请重新输入>");
	}
	
}

void Computer_Do(char board[ROW][COL], int level){
	printf("电脑走\n");
	while(1)
	{
		x=rand()/level;
		y=rand()/level;
		if(Judge_Legal(board, level, x, y)==0)
		{
			board[x][y]='O';
			break;
		}
	
	}
}

char Judge_Win(char board[ROW][COL], int level, int num){
	int px=0, py=0;
	int count=0;
	char c=board[x][y];
	//printf("x=%d, y=%d \n ", x, y);
	//printf("c=%c\n",c);
	if (c=='X' || c=='O')
	{
		count=0;
		px=x;
		py=0;																			
		while(px>=0 && px<level && py>=0 && py<level)			//一横排
		{

			(board[px][py]==c) ? (count ++) : (count=0);

			if(count>=num)		return c;
			py++;
		}

		count=0;
		py=y;
		px=0;
		while(px>=0 && px<level && py>=0 && py<level)			//一列排
		{	

			(board[px][py]==c) ? (count ++) : (count=0);

			if(count>=num)		return c;
			px++;
		}

		if(x<y)							//从左上角到右下角
		{
			px=0;
			py=(y-x);
		}
		else
		{
			px=(x-y);
			py=0;
		}
		count=0;
		while(px>=0 && px<level && py>=0 && py<level)
		{

			(board[px][py]==c) ? (count ++) : (count=0);

			if(count>=num)		return c;
			px++;
			py++;
		}

		if( (level-(x+1))>y )        //从左下角到右上角
		{
			px=x+y;
			py=0;
		}
		else
		{
			px=level-1;
			py=y-(level-(x+1));
		}
		count=0;
		while(px>=0 && px<level && py>=0 && py<level)
		{
			
			(board[px][py]==c) ? (count ++) : (count=0);

			if(count>=num)		return c;
			px--;
			py++;
		}

	}


	for(px=0; px<level; px++)
	{
		for(py=0; py<level; py++)
		{
			if(board[px][py]==' ') goto Loop1;
		}
	}
	return 'q';
Loop1:
	return 'k';
}