# include <stdio.h>

#define NUM 19 // defined and const are very alike
const int c = 10;// const is a number that cannot be changed once defined and can be used without 'extern'
int gCount;

int* test();
int* test()
{
	int count;
	printf("value of undefined local variable is %d\n", count);
	count = 0;
	static int sCount[19];
	printf("address is %d\n", sCount);
	extern int gCount;
	register int i;
	for(i=0; i < NUM ;i++)
	{
		//printf("global number %d\n", gCount);
		gCount++ ;
		//printf("local number %d\n", count);
		count++;
		sCount[i] = count;
	}
	return sCount;
}


void main()
{
	{
		char num[14] = "block for test";
		printf("address of this string is %d\n", num);
		printf("%s\n", num);
		printf("the 1st word of this string is %c\n", num[0]);
	}

	printf("const number %d\n", c);
	printf("defined number %d\n", NUM);
	
	extern int gCount;
	printf("value of undefined global variable is %d\n", gCount);
	gCount = 1;
	int* sCount = test();
	printf("now global number is %d\n", gCount);
	printf("address of static number is %d\n", sCount);
	register int i;
	for (i=0;i<NUM;printf("%d\n",sCount[i]),i++);
}
