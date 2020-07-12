# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define H 2
# define V 4
# define tolerance 3

void test();
void test()
{
	int multi[H][V] = {{1,2,3,4},{3,4,5,6}};
	int (*p)[V];
	p = &multi[0];
	int *pp;
	pp = &multi[0][0]; 
	register int i;
	for (i = 0;i < H ;i++)
	{
		printf("address is %d\n", p);
		printf("address is %d\n", *p);
		printf("values is %d\n", **p);
		p ++;
		int j = 0;
		for (;j < V;j++)
		{
			printf("inner address is %d\n", pp);
			printf("value is %d\n", *pp);
			pp++;
		}
	}
	
}

void test1();
void test1()
{
	char *log[3] = {"hello","it's","me"};
	int i = 0;
	for (;i < 3;i++)
	{
		printf("string is %s\n", log[i]);// log[i] is a pointer
		printf("the address of this string is %d\n", log[i]);
		printf("the first char of the string is %c\n", log[i][0]);
		printf("the first char is %c\n", *log[i]); 
		printf("the address is %d\n", &log[i][0]);
	}
}

void test2();
void test2()
{
	int x = 3;
	int *p = &x;
	int **pp = &p;
	**pp = 100;
	printf("x is %d\n", x);
}

///////////////////////////////////
void test3(char *p[]);
void test3(char *p[])
{
	puts("please type in some words but do not enter empty strings more than 3 times!");
	puts("the last string must be \\t");
	int i = 0;
	int signal = 0;
	while(1)
	{
		if(p[i] == "\t") 
		{
			break;
		}
		printf("string length is %d\n", strlen(p[i]));
		if (strlen(p[i]) == 0)
		{
			printf("empty string detected!\n");
			signal ++;
			i++;
			if (signal > tolerance) 
				break;
		}
		else 
		{
			printf("string is %s\n", p[i]);
			i++;
		}
	}
	printf("there are %d strings and %d empty strings\n", i, signal);
}

void test4();
void test4()
{
	char str[12][12];
	char *p;
	p = &str[0][0];
	register int i = 0;
	for(;i < 12;i++)
	{
		register int j = 0;
		for(;j < 12;j++)
		{
			str[i][j] = 'X';
		}
	}
	i = 0;
	for (;i < 12;i++)
	{
		int j = 0;
		for (;j < 12;j++)
		{
			printf("|%c| ", *p);
			p++;
		}
		printf("\n");
	}
}

void main()
{
	char *p[] = {"he","he","","the","","","hello","\t"};
	test3(p);
}
