#include <stdio.h>
#include <stdlib.h> 

void test();
void test()
{
	int a[10];
	int b[10];
	int* pa = a;
	int* pb = b;
	
	int i;
	for(i = 0; i < 10 ; i++)
	{
		printf("%d\n",pa);
		printf("%d\n",pb);
		printf("%d\n",sizeof(pa));
		pa++;
		pb++;
	}
}

void main()
{
	test();
	system("pause");
}

