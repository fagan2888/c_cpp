# include <stdio.h>
# include <stdlib.h>

void test();
void test()
{
	int a, NUM, count;
	puts("how many people will join this game? please enter an integer:"); 
	scanf("%d", &NUM);
	puts("how many lucky dogs do you want?");
	scanf("%d", &count);
	if (count > NUM)
	{
		printf("error!");
		system("pause");
		exit(0);
	}
	puts("lucky numbers are as follows:");
	
	char flag;
	while(1)
	{
		printf("%d\n", rand()%NUM);
		scanf("%c", &flag);
		if (flag ==	'\n')
			break;
	}
	
	int index[NUM];
	register int i;
	for (i = 0;i < NUM;i++)
	{
		index[i] = 0;
	}
	register int k;
	for (k = 0;k < count;k++)
	{
		a = rand()%NUM;
		if (index[a] == 1)
		{
			continue;
		}
		else	
		{
			index[a] = 1;
			printf("%d\n",a);
		}
	}
	
	printf("congratulations to all of you!");
	system("pause");	
} 

void test1();
void test1()
{
	char flag;
	int NUM = 12;
	while(1)
	{
		printf("%d\n", rand()%NUM);
		scanf("%c", &flag);
		if (flag ==	'\n')
			break;
	}
}

void main()
{
	test1();
} 
