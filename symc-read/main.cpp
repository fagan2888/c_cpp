#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <process.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define BUF_SIZE 4096

int main(int argc, char** argv) {

	// 创建共享文件句柄
	HANDLE hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,
		NULL,
		PAGE_READWRITE,
		0,
		BUF_SIZE,
		"shareMemory");
		
	// 映射缓存区视图，得到共享内存的指针
	LPVOID lpBase = MapViewOfFile(
		hMapFile,
		FILE_MAP_ALL_ACCESS,
		0,
		0,
		BUF_SIZE);
		
	DWORD dw = 0;
	HANDLE hSemaphoreBufEmpty = CreateSemaphore(NULL, 1, 1, "bufEmpty");
	HANDLE hSemaphoreBufFull = CreateSemaphore(NULL, 0, 1, "bufFull");
	
	while(1)
	{
		// P(bufFull)
		dw = WaitForSingleObject(hSemaphoreBufFull, INFINITE);
		
		char buffer[BUF_SIZE] = "\0";
		strcpy(buffer, (char*)lpBase);
		printf("got message %s \n", buffer);
		printf("data<- buffer\n");
		if(strcmp(buffer, "bye") == 0)
		{
			printf("exit, bye !\n");
			Sleep(100);
			break;
		}
		
		// V(bufFull)
		ReleaseSemaphore(hSemaphoreBufEmpty, 1, NULL);
	}
	
	UnmapViewOfFile(lpBase);
	CloseHandle(hMapFile);	
	
	return 0;
}
