# include <stdio.h>
# include <stdlib.h>

register int x;
int status;
void test();
void test()
{
	extern int x;
	extern int status;
	for(x=0; x<10;x++)
	{
		if(x%2 == 0)
		{ 
			
			switch (x%4)// actually "swith case break" is the same as "if goto" but in every case we need to go to the same line! moreover break has different meanings in goto and case
			{
				case 0: 					
					puts("this number can be exactly dividend by 4");break;
				case 1:
					puts("if this number is dividend by 4 we can get 1 as remainder");break;
				default: 
					printf("%d\t",x),puts("if this number is dividend by 4 we can get a remainder bigger than 1");
			}
			
			/*
			if (x%4 == 0)
			{
			    puts("this number can be exactly dividend by 4");
				goto line;
			}
			else if (x%4 == 1)
			{
			   	puts("if this number is dividend by 4 we can get 1 as remainder");
				goto line;
			}
			else
			{
				printf("%d\t",x);
				puts("if this number is dividend by 4 we can get a remainder bigger than 1");
			}
			*/
			line: continue;
		} 
		else if (x == 7)
			break;
		else
			printf("%d\n",x); 
	}
	if (x>7)
	{
		status = EXIT_SUCCESS;
		//exit(EXIT_SUCCESS);
	}
	else
	{
		status = EXIT_FAILURE;
		//exit(EXIT_FAILURE);
	}
}

void main()
{
	extern int status;
	printf("status %d\n",status);
	test();
	printf("status %d\n",status);
}
