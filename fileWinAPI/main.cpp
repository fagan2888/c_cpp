#include <tchar.h>
#include <Windows.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	setlocale(LC_ALL, "chs");
	
	BOOL ret;
	TCHAR* filePath = _T("C://Users//86156//Desktop//wina.txt");

	DWORD dwDesireAccess = GENERIC_READ | GENERIC_WRITE;
	DWORD dwShareMode = 0;
	
	LPSECURITY_ATTRIBUTES lpSecurityAttributes = NULL;
	DWORD dwCreationDisposition = OPEN_ALWAYS;
	DWORD dwFlagsAndAttributes = FILE_ATTRIBUTE_NORMAL;
	HANDLE hTemplateFile = NULL;
	
	HANDLE handle = CreateFile(
		filePath,
		dwDesireAccess,
		dwShareMode,
		lpSecurityAttributes,
		dwCreationDisposition,
		dwFlagsAndAttributes,
		hTemplateFile); 
		
	if(handle == NULL)
	{
		printf("CreateFile failed(%ld)", GetLastError());
	}
	else
	{
		DWORD len;
		CHAR* writeBuf = "Win APi hello\0";
		CHAR readBuf[1024];
		
		// ASCII 8bit 没前缀 
		// Unicode 16bit 前缀：0xFEFF 
		// utf-8 8bit 16bit etc 前缀：0xEFBBBF
		
		ret = WriteFile(handle, writeBuf, lstrlen(writeBuf)*sizeof(CHAR), &len, NULL); 
		if(ret == 0)
		{
			printf("WriteFile buf failed(%d)", GetLastError());
		}
		else
		{
			printf("WriteFile buf = %s -> wirteLen = %d\n", writeBuf, len);
		}
		
		// SetFilePointer : fseek
		// DWORD SetFilePointer(HANDLE hFile, LONG, PLONG, DWORD dwMoveMethod)
		// 		FILE_BEGIN, FILE_END, FILE_CURRENT
		
		DWORD pos = SetFilePointer(handle, 0, 0, FILE_BEGIN);
		
		if(pos == HFILE_ERROR)
		{
			printf("SetFilePointer failed(%d)\n", GetLastError());	
		} 
		else
		{
			printf("SetFilePointer -> pos = %d\n", pos);
		}
		
		// BOOL ReadFile(HANDLE hFile, buf, int size, int* bytesRead, lpOverlapped)
		ret = ReadFile(handle, readBuf, 1024, &len, NULL);
		
		if(ret == 0)
		{
			printf("read file failed!(%d)\n", GetLastError());	
		}
		else
		{
			readBuf[len/sizeof(CHAR)] == L'\0';
			printf("ReadFile -> len = %d, buf = %s\n", len, readBuf);
		} 
		
		CloseHandle(handle);
	}
	
	return 0;
}
