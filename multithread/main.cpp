#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <windows.h>
#include <process.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define BUF_SIZE 4096 

HANDLE hSemaphoreBufEmpty = NULL;
HANDLE hSemaphoreBufFull = NULL;
char buffer[BUF_SIZE] = "\0";
BOOL blExit = FALSE;

void WINAPI WriteThreadFunc(void* param)
{
	while(!blExit)
	{
		// P(BufEmpty)
		DWORD dw = WaitForSingleObject(hSemaphoreBufEmpty, INFINITE);
		
		printf("Thread[W]: input a word:\n");
		scanf("%s", buffer);
		
		if(strcmp(buffer, "bye") == 0)
		{
			printf("Thread[W]: exit bye!\n");
			Sleep(100);
			blExit = TRUE;
			break;
		}
		printf("Thread[W]: you have just input %s:\n", buffer);
		
		// V(BufFull)
		ReleaseSemaphore(hSemaphoreBufFull, 1, NULL);
		Sleep(100);
	}
}

void WINAPI ReadThreadFunc(void* param)
{
	while(!blExit)
	{
		// P(BufFull)
		DWORD dw = WaitForSingleObject(hSemaphoreBufFull, INFINITE);
		
		printf("Thread[R]: got message: %s\n", buffer);
		memset(buffer, 0, BUF_SIZE);
		
		// V(ButEmpty)
		ReleaseSemaphore(hSemaphoreBufEmpty, 1, NULL);
		Sleep(100);	
	}
}

int main(int argc, char** argv) {
	
	hSemaphoreBufEmpty = CreateSemaphore(NULL, 1, 1, "BufEmpty");
	
	if(GetLastError() == ERROR_ALREADY_EXISTS)
	{
		printf("ERROR: the semaphore BufEmpty exists! \n");
		CloseHandle(hSemaphoreBufEmpty);
		return 0;
	}
	
	hSemaphoreBufFull = CreateSemaphore(NULL, 0, 1, "BufFull");
	
	if(GetLastError() == ERROR_ALREADY_EXISTS)
	{
		printf("ERROR: the semaphore BufFull exists! \n");
		CloseHandle(hSemaphoreBufEmpty);
		CloseHandle(hSemaphoreBufFull);
		return 0;
	}
	
	// start threads
	DWORD dwWriteThreadID = 0;
	HANDLE hThreadW = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)WriteThreadFunc, NULL, 0, &dwWriteThreadID);
	DWORD dwReadThreadID = 0;
	HANDLE hThreadR = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ReadThreadFunc, NULL, 0, &dwReadThreadID);
	 
	while(!blExit)
	{
		Sleep(500);	
	}
	CloseHandle(hSemaphoreBufEmpty);
	CloseHandle(hSemaphoreBufFull); 
	
	return 0;
}
