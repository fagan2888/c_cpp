# include <stdio.h>
# include <stdlib.h>
# include <string.h>

float devide(float, float);
float devide(float t1, float t2) 
{
	return t1/t2;
}

float time(float, float);
float time(float t1, float t2) 
{
	return t1*t2;
}

float plus(float, float);
float plus(float t1, float t2) 
{
	return t1+t2;
}

float subtract(float, float);
float subtract(float t1, float t2) 
{
	return t1-t2;
}

float (*pfunc)(float, float);

//now we know that not only an array's name but also a function name is a pointer!
float test(float, float, char choice);
float test(float x, float y, char choice)
{
	switch (choice)
	{
		case '/': pfunc = devide;break;
		case '*': pfunc = time;break;
		case '+': pfunc = plus;break;
		case '-': pfunc = subtract;break;
		default : puts("error\n");break;
	} 
	return pfunc(x,y);
}

void main()
{
	printf("answer is %f\n", test(1.0, 2.0, '*'));
}
