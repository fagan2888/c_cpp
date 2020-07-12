# include <stdio.h>
# include <conio.h>

# define MAXBUFFER 10 

void test();
void test()
{
	char ch = '\t';
	//while(ch != '\n')
	while(ch != '\r')
	{
		//ch = getchar();
		//ch = getch();
		ch = getche();
		//putchar(ch);
	}
	puts("that is what you have typed in");
}

void test2();
void test2()
{
	char buffer[MAXBUFFER];
	puts("what you typing in will be cut into lines with no more than 10 words:");
	while(1)
	{
		fgets(buffer, MAXBUFFER, stdin);// stdin is a key word that you don't need to define, fgets get characters from stdin
		if (buffer[0] == '\n')
			break;
		puts(buffer);
	}
}
	
void test3();
void clean();
void test3()
{
	typedef struct info{
		char name[10];
		int age;
		char phone[12];
		char address[50];
	} INFO;
	INFO myinfo;
	INFO *pinfo;
	pinfo = &myinfo;
	puts("how old are you?");
	scanf("%d", &myinfo.age);
	//clean();
	fflush(stdin);// fflush has a function like "git stash clear" which is an order used in git
	puts("what is your name?");
	scanf("%s",&pinfo->name);
	clean();
	puts("what is your phone number?");
	scanf("%s",&myinfo.phone);
	clean();
	puts("where are you living now?");
	scanf("%s",&myinfo.address);
	printf("\nyou are %d years old\n", myinfo.age);
	printf("your name is %s\n",myinfo.name);
	printf("your phone number is %s\n", myinfo.phone);
	printf("you are living at %s now\n", myinfo.address);
}
void clean()
{
	char junk[100];
	gets(junk);
	//fgets(junk, 100, stdin);// stdin is something like a stash
}
	
void test4();
void log(char *msg);
void test4()
{
	
	register int i = 0 ;
	for(i = 14;i< 128;i++)
	{
		putchar(i);
	}
	char string[] = "\nhello world!";
	for(i = 0;i<sizeof(string)+100;i++)
	{
		if (string[i]!='\0')
			putchar(string[i]);
			//fputc(string[i],stdout);// stdout is something like a stash
		else
		{
			putchar('\0');
			break;
		}
	} 
	fputs("\nhi there\n",stdout);
	char msg[] = "this is a log";
	char *p;
	p = &msg;
	log(p);
}
void log(char *msg) 
{
	fprintf(stderr, msg);
}

void main()
{
	test4();
}
