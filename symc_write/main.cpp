#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <process.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define BUF_SIZE 4096

int main(int argc, char** argv) {
	// ���������ļ����
	HANDLE hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,
		NULL,
		PAGE_READWRITE,
		0,
		BUF_SIZE,
		"shareMemory");
		
	// ӳ�仺������ͼ���õ������ڴ��ָ��
	LPVOID lpBase = MapViewOfFile(
		hMapFile,
		FILE_MAP_ALL_ACCESS,
		0,
		0,
		BUF_SIZE);
		
	DWORD dw = 0;
	HANDLE hSemaphoreBufEmpty = CreateSemaphore(NULL, 1, 1, "bufEmpty");
	HANDLE hSemaphoreBufFull = CreateSemaphore(NULL, 1, 1, "bufFull");
	
	while(1)
	{
		// P(bufEmpty)
		dw = WaitForSingleObject(hSemaphoreBufEmpty, INFINITE);
		
		char buffer[BUF_SIZE] = "\0";
		printf("input a word: \n");
		scanf("%s", buffer);
		if(strcmp(buffer, "bye") == 0)
		{
			printf("exit, bye !\n");
			Sleep(100);
			break;
		}
		
		printf("you have just input: %s \n", buffer);
		strcpy((char*)lpBase, buffer);
		printf("buffer <- data\n");
		
		// V(bufFull)
		ReleaseSemaphore(hSemaphoreBufFull, 1, NULL);
	}
	
	CloseHandle(hSemaphoreBufEmpty);
	CloseHandle(hSemaphoreBufFull);
	
	UnmapViewOfFile(lpBase);
	CloseHandle(hMapFile);
	 
	return 0;
}
