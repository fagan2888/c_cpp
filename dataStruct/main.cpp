#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct node 
{
	int data;
	struct node * next;
} Node;

typedef Node* linkList;

int init(linkList* a)
{
	printf("start\n");
	*a = (linkList)malloc(sizeof(Node));
	printf("begin\n");
	if(!(*a))
	{
		printf("error");
		return 0;
	}
	(*a)->next = NULL;
	printf("ok");
	return 1;
}

void linkListJoint()
{

	Node a[3];
	Node b[3];
	a[0].data = 1;
	a[1].data = 3;
	a[2].data = 6;
	a[0].next = &a[1];
	a[1].next = &a[2];
	a[2].next = NULL;
	
	b[0].data = 2;
	b[1].data = 4;
	b[2].data = 5;
	b[0].next = &b[1];
	b[1].next = &b[2];
	b[2].next = NULL; 
	
	Node * pa = &a[0];
	Node * pb = &b[0];
	int c[6];
	int k,ca = 0, cb = 0;
	for(k = 0;k<6;k++)
	{
		if(((pa->data <= pb->data)&&(ca < 3))||(cb >= 3))
		{
			c[k] = pa->data;
			pa++;
			ca++;
		}
		else
		{
			c[k] = pb->data;
			pb++;
			cb++;
		}
		printf("->%d", c[k]);
	}
}

int main(int argc, char** argv) {

	//linkListJoint();
	linkList * a;
	int flag;
	flag = init(a);
	
	return 0;
}
