# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void addToHead();
void addToHead()
{
	printf("ok");
}

void addToTail();
void addToTail()
{
	
}

void addToMiddle();
void addToMiddle()
{
	
}

void subFromHead();
void subFromHead()
{
	
}

void subFromTail();
void subFromTail()
{
	
}

void subFromMiddle();
void subFromMiddle()
{
	
}

void (*pfunc)();

void test(char *, int);
void test(char *str, int pos)
{
	typedef struct info{
		char name[100];
		char phone[20];
		int year;
		struct info *next;
	} INFO;

	INFO infos[5], *pinfo;
	
	strcpy(infos[0].name, "first");
	strcpy(infos[1].name, "second");
	strcpy(infos[2].name, "third");
	strcpy(infos[3].name, "fourth");
	strcpy(infos[4].name, "fifth");
	int i = 1;
	pinfo = infos;
	for (;i < 4;i++)
	{
		pinfo->next = &infos[i];
		pinfo ++;
	}
	pinfo->next = NULL;
	
	printf("fourth name is %s\n", infos[2].next->name);
	
	INFO *new;
	INFO *head;
	head = NULL;
	
	if(str == "add head")
		pfunc = addToHead;	
	else if(str == "add tail")
		pfunc = addToTail;
	else if(str == "sub head")
		pfunc = subFromHead;
	else if(str == "sub tail")
		pfunc = subFromTail;
	else if(str == "add middle")
		pfunc = addToMiddle;
	else if(str == "sub middle")
		pfunc = subFromMiddle;
	else
		puts("error");
	
	pfunc();
}

void main()
{
	char *str = "add head";
	int pos = 0;
	test(str, pos);
}
