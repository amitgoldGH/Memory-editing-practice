// ProcessManipulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <windows.h>
#include <iostream>

#include <vector>

using namespace std;

int readAmmo(DWORD* ammoAddress, int numOfAddresses, LPCSTR processName)
{
	DWORD pid;
	int* ammoCountArray = new int[numOfAddresses];
	HWND hWnd = FindWindowA(0, processName);
	if (hWnd == NULL) {
		cout << "Window not found" << endl;
		Sleep(3000);
		exit(-1);
	}
	GetWindowThreadProcessId(hWnd, &pid);
	if (pid == NULL) 
	{
		cout << "process id not found" << endl;
		Sleep(3000);
		exit(-1);
	}
	HANDLE hProcess = OpenProcess(PROCESS_VM_READ, FALSE, pid);
	while (true)
	{
		for (int i = 0; i < numOfAddresses; ++i)
		{
			ReadProcessMemory(hProcess, (LPVOID)ammoAddress[i], &ammoCountArray[i], sizeof(ammoCountArray[i]), 0);
			switch (i) {
				case 0:
				{
					cout << "Rifle ammo : ";
					break;
				}
				case 1: 
				{
					cout << "Pistol ammo : ";
					break;
				}
				case 2: {
					cout << "Akimbo ammo: ";
					break;
				}
			}
			cout << ammoCountArray[i] << endl;
		}
		
		Sleep(350);
		system("CLS");
	}
	CloseHandle(hProcess);
	return 0;
}
int editAmmo(DWORD ammoAddress, LPCSTR processName)
{
	int count = 150;
	DWORD pid;
	HWND hWnd = FindWindowA(0, processName);
	if (hWnd == NULL) {
		cout << "Window not found" << endl;
		Sleep(3000);
		exit(-1);
	}

	GetWindowThreadProcessId(hWnd, &pid);
	if (pid == NULL)
	{
		cout << "process id not found" << endl;
		Sleep(3000);
		exit(-1);
	}

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	while (true)
	{
		WriteProcessMemory(hProcess, (LPVOID)ammoAddress, &count, sizeof(count), 0);
		Sleep(300);
	}
	CloseHandle(hProcess);
	return 0;
}

int main()
{
	vector<DWORD> addressVector;
  
	DWORD rifleAmmoAddress = 0x00E4A4D8;
	DWORD pistolAmmoAddress = 0x00E4A4C4;
	DWORD akimboAmmoAddress = 0x00E4A4E4;
	DWORD grenadeaddress = 0x00E4A4E0;
	DWORD healthAddress = 0x00E4A480;
	DWORD armorAddress = 0x00E4A484;
	// Addresses change each time the game starts.

	addressVector.push_back(rifleAmmoAddress);
	addressVector.push_back(pistolAmmoAddress);
	addressVector.push_back(akimboAmmoAddress);
	addressVector.push_back(grenadeaddress);
	addressVector.push_back(healthAddress);
	addressVector.push_back(armorAddress);


	LPCSTR str = "AssaultCube";
	int count = 500;

	DWORD pid;
	HWND hWnd = FindWindowA(0, str);
	if (hWnd == NULL) {
		cout << "Window not found" << endl;
		Sleep(3000);
		exit(-1);
	}

	GetWindowThreadProcessId(hWnd, &pid);
	if (pid == NULL)
	{
		cout << "process id not found" << endl;
		Sleep(3000);
		exit(-1);
	}

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	while (true)
	{
		for (DWORD word : addressVector)
		{
			WriteProcessMemory(hProcess, (LPVOID)word, &count, sizeof(count), 0);
		}
		
		Sleep(300);
	}
	CloseHandle(hProcess);
	return 0;

	cin.get();
	return 0;
}

