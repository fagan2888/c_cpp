#include <iostream>
#include <Windows.h>
#include <tchar.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	TCHAR szCommandLine[] = _T("E:\codes\c_cpp\helloWorld.exe");
	
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	
	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));
	
	// create a new prrocess
	if (CreateProcess(
		NULL,
		szCommandLine,
		NULL,
		NULL,
		false,
		CREATE_NEW_CONSOLE,
		NULL,
		NULL,
		&si,
		&pi))
	{
		cout<< "create process successfully" << endl;
	}
	else
	{
		DWORD wd = GetLastError();
		cerr<< "failed to create process: code = "<< wd << endl;	
	}
	
	system("pause");
	
	TerminateProcess(pi.hProcess, 300);
	
	return 0;
}
