# include <stdio.h>

void test();
void test()
{
	struct info {
		char name[10];
		int phone;
		char address[10];
	};
	
	struct info new;
	struct info *pnew;
	strcpy(new.name, "test");
	pnew = &new;
	pnew->phone = 123455;
	strcpy((*pnew).address, "test");
	printf("name is %d\n", new.phone);
	printf("phone is %s\n", pnew->name);
	printf("address is %s\n", new.address);
	printf("name address is %d\n", pnew);
	printf("phone address is %d\n", pnew+1);
 } 
 
 void main()
 {
 	test();
 }
