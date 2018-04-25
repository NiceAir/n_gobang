#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

extern int x, y;
void Creat_Rule(int *level, int *num, int *Pioneer){
	int c=0;
	char affirm[5]={'\0'};
Loop:
		printf("��ѡ�����̴�С��3�׵�36�ף�>");
		while(scanf("%d", level))
		{
			int c=0;
			while((c = getchar()) != '\n' && c != EOF);     //������̻�����������д��

			if(*level<3) printf("�������������ָ��\n");
			else
			{
				break;
			}	
		}
		printf("�����漸�����飿������С��3��>");
		while(scanf("%d", num))
		{
			int c=0;
			while((c = getchar()) != '\n' && c != EOF);     //������̻�����������д��
			if(*num<3) printf("�����������������\n");
			else if(*num>*level)
			{
				printf("���������̵ķ�Χ������������\n");
			}
			else
			{
				break;
			}
		}
		printf("���͵���˭���ߣ����������ߣ�����1�����������ߣ�����2��>");
		while(scanf("%d", Pioneer))
		{
			int c=0;
			while((c = getchar()) != '\n' && c != EOF);     //������̻�����������д��
			if(*Pioneer!=1 && *Pioneer!=2) printf("�����������������\n");
			else
			{
				break;
			}
		}
		printf("��ȷ�Ϲ���\n");
		if(*Pioneer==1) printf("�����ƵĹ���Ϊ�� ��һ��%d*%d�������ϣ�˭�Ƚ�%d����������һ����˭��Ӯ�ˣ�������\n", *level, *level, *num);
		else  printf("�����ƵĹ���Ϊ�� ��һ��%d*%d�������ϣ�˭�Ƚ�%d����������һ����˭��Ӯ�ˣ���������\n", *level, *level, *num);
		printf("****************ȷ�ϲ���ʼ��Ϸ��(Y/N)>");
		scanf("%s", affirm);

		while((c = getchar()) != '\n' && c != EOF);     //������̻�����������д��
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
	printf("Tips: ���Ͻ�Ϊ��1,1�������½�Ϊ��%d��%d��\n", level, level);
	printf("�����>");
	while(scanf("%d%d", &a,&b))
	{
		int c=0;
		while((c = getchar()) != '\n' && c != EOF);     //������̻�����������д��
		x=a-1;
		y=b-1;
		if(Judge_Legal(board, level, x, y)==0)
		{
			board[x][y]='X';
			break;
		}
		else if(Judge_Legal(board, level, x, y)==1)
		{
			printf("�������λ�ò��Ϸ�������������>");
		}
		else printf("�����Ѿ��������ˣ�����������>");
	}
	
}

void Computer_Do(char board[ROW][COL], int level){
	printf("������\n");
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
		while(px>=0 && px<level && py>=0 && py<level)			//һ����
		{

			(board[px][py]==c) ? (count ++) : (count=0);

			if(count>=num)		return c;
			py++;
		}

		count=0;
		py=y;
		px=0;
		while(px>=0 && px<level && py>=0 && py<level)			//һ����
		{	

			(board[px][py]==c) ? (count ++) : (count=0);

			if(count>=num)		return c;
			px++;
		}

		if(x<y)							//�����Ͻǵ����½�
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

		if( (level-(x+1))>y )        //�����½ǵ����Ͻ�
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