#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
	DWORD pid;
	DWORD varIntAddress = 0;
	DWORD varIntPtrAddress = 0;
	DWORD varIntPtr2Ptr2Address = 0;
	cout << "Enter pid: ";
	cin >> dec >> pid;
	cout << endl;
	cout << pid;

	HANDLE processHandle = OpenProcess(PROCESS_VM_READ, FALSE, pid);
	if (processHandle == NULL)
	{
		cout << "Failed to get handle!" << endl;
		system("pause");
		exit(-1);
	}

	cout << "\nEnter varIntPtr2Ptr2 address: ";
	cin >> hex >> varIntPtr2Ptr2Address;
	cout << endl;

	
	DWORD intPtrRead;
	int read;
	ReadProcessMemory(processHandle, (LPVOID)varIntPtr2Ptr2Address, &intPtrRead, sizeof(intPtrRead), 0);
	ReadProcessMemory(processHandle, (LPVOID)intPtrRead, &intPtrRead, sizeof(intPtrRead), 0);
	ReadProcessMemory(processHandle, (LPVOID)intPtrRead, &intPtrRead, sizeof(intPtrRead), 0);
	ReadProcessMemory(processHandle, (LPVOID)intPtrRead, &read, sizeof(read), 0);
	cout << endl << read << endl;
	system("pause");
	CloseHandle(processHandle);
	return 0;
}
