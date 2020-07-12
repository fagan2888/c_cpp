#include <stdio.h>
#include <stdlib.h>
# define NU 5

int* test(int NUM);
int* test(int NUM)
{
	int a[NUM];
	int* pa = a ;
	
	for(int i = 0;i<NUM;i++)
	{
		a[i] = i+6;
		printf("value is %d\n", a[i]);
		printf("address is %d\n", pa);
		pa++;
	}
	return pa -= NUM;
}

void main()
{
	int* b = test(NU);
	printf("the first address is %d\n", b);
	system("pause");
 } 
