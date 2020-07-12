# include <stdio.h>

int x;

void test();
void test()
{
	extern int x;
	printf("%d\n",x);
}

int main(void)
{	
	extern int x;
	static int tally = 0;
	for (x=0;x<101;x++)
	{
		if(x%2 == 0)
			tally++;
	}
	printf("%d\n", tally);
	test();
	return 0;	
} 
