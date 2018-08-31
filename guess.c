#include <stdio.h>
#include <stdlib.h>

int LEVEL=100;
int ANSWER=0;
void judgeNumber(int);
void setLevel(int);
void success();
void begin();

void judgeNumber(int number)
{
	if(number == ANSWER)
		success();
	else if(number > ANSWER)
		printf("很遗憾，猜大了！\n");
	else
		printf("很遗憾，猜小了！\n");

}

void setLevel(int level)
{
	int b=0;
	while(!b)
	{
		switch(level)
		{
			case 1:
			{
				LEVEL=100;
				b=1;
				break;
			}
			case 2:
			{
				LEVEL=1000;
				b=1;
				break;
			}
			case 3:
			{
				LEVEL=10000;
				b=1;
				break;
			}
			default:
			{
				printf("输入错误，请重新输入！\n");
				exit(-1);
			}

		}
	}
}

void success()
{
	printf("恭喜你，猜对了！\n");
	exit(0);
}

void begin()
{	
	int level,guess;
	printf("请选择等级：\n1. 1~100    2. 1~1000  3. 1~10000\n ");
	scanf("%d",&level);
	setLevel(level);
	srand(time(NULL));
	ANSWER=rand()%LEVEL+1;
	while(1)
	{
		printf("请输入你要猜的数：\n");
		scanf("%d",&guess);
		judgeNumber(guess);
	}
}

int main()
{
	begin();
	return 0;
}

