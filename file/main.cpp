#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h> 

#define lineLength 100 

typedef struct 
{
	int iData;
	char cChar;
	char cChar2;
} Data;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	FILE* file;
	
	// open a file
	// r: open a file that already exists with read only mode
	// r+: open a file that already exists with read and write mode
	// rb+: open a binary file that already exists with read and write mode
	// rt+: open a text file that already exists with read and write mode
	// w: open a file with write mode file will be deleted if already exists
	// w+: open a file with read and write mode
	// a: open a file with append mode if the file not exists it will be created   
	// a+: open a file with read and append mode if the file not exists it will be created
	// wb, wb+, ab, ab+
	
	/*
	//read and write text
	char buffer[lineLength];
	char buffer1[lineLength] = "hello world!\r\n";
	char buffer2[lineLength] = "Line2: test\r\n";
	char* mode = "at+";
	file = fopen("C:\\Users\\86156\\Desktop\\file.txt", mode);
	
	if(file == NULL)
	{
		printf("open file file.txt failed!\n");	
	} 
	else
	{
		printf("open file file.txt successfully!\n");
		// read
		// int fscanf(File *f, const char* format, ...)
		while(fscanf(file, "%s", buffer) != EOF)
		{
			printf("%s:%d\n", buffer, ftell(file));
		}
		
		// write
		// int fprintf(File *f, const char* format, ...)
		//fprintf(file, "%s", buffer1);
		//fprintf(file, "%s", buffer2);
		
	}
	fclose(file);
	*/
	
	
	// read and write the binary file
	Data a, b, c;
	
	a.iData = 53;
	a.cChar = 'a';
	a.cChar2 = 'd';
	
	b.iData = 56;
	b.cChar = 'c';
	b.cChar2 =  'e';
	
	file = fopen("C:/Users/86156/Desktop/binary.b", "wb+");
	
	if(file == NULL)
	{
		printf("open file failed!\n");
	}
	else
	{		
		//fwrite((void*)p, int size, int count, File *f)
		if(fwrite(&a, sizeof(Data), 1, file) != 1)
		{
			printf("write in error!\n");
		}
		
		if(fwrite(&b, sizeof(Data), 1, file) != 1)
		{
			printf("write in error!\n");
		}
		
		// int fseek(FILE *f, long offset, int origin)
		// origin: 
		// 		SEEK_SET(start point), SEEK_END(end point), SEEK_CUR(current position)
		fseek(file, 0L, SEEK_SET);
		fread(&c, sizeof(Data), 1, file);
		printf("%d.%c.%c\n", c.iData, c.cChar, c.cChar2);
		
		fseek(file, sizeof(Data), SEEK_SET);
		fread(&c, sizeof(Data), 1, file);
		printf("%d.%c.%c\n", c.iData, c.cChar, c.cChar2);
		
	}
	fclose(file);
	
	return 0;
}
