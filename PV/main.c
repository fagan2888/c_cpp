#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <process.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	DWORD dw = 0;
	BOOL created = TRUE;
	HANDLE hMutex = CreateMutex(NULL, FALSE, "Test001");
	if(GetLastError() == ERROR_ALREADY_EXISTS)
	{
		created = FALSE;
		printf("Mutex exists, waiting ...");	
	} 
	
	while(1)
	{ 	
		// P ‘≠”Ô
		dw = WaitForSingleObject(hMutex, INFINITE);
		
		char buffer[1024] = "\0";
		printf("input a word\n");
		scanf("%s", buffer);
		
		if(strcmp(buffer, "bye") == 0)
		{
			printf("exit bye!");
			Sleep(100);
			break;
		}
		
		printf("you have just input: %s\n", buffer);
		
		// V ‘≠”Ô
		ReleaseMutex(hMutex); 
		Sleep(100);
	}
	
	if(created)
	{
		CloseHandle(hMutex);
		hMutex = NULL;
	}
			
	return 0;
}
