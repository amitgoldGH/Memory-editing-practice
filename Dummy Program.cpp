// Dummy Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <iomanip>
using namespace std;

int main()
{
	int varInt = 123456;
	string varString = "DefaultString";
	char arrChar[128] = "Long char array right there ->";
	
	int* ptr2int = &varInt;
	int** ptr2ptr = &ptr2int;
	int*** ptr2ptr2 = &ptr2ptr;

	while (true)
	{
		cout << "Process ID: " << GetCurrentProcessId() << endl;
		cout << endl;

		cout << left << setw(15) << setfill(' ') << "varInt"
			<< "(0x" << &varInt << ") = " << left << setw(10) << setfill(' ') << varInt << endl;
		
		cout << left << setw(15) << setfill(' ') << "varString" 
			<< "(0x" << &varString << ") = " << left << setw(10) << setfill(' ') << varString << endl;
		
		cout << left << setw(15) << setfill(' ') << "arrChar[128]"
			<< "(0x" << &arrChar << ") = " << left << setw(50) << setfill(' ') << arrChar << endl;
		cout << endl;


		cout << left << setw(15) << setfill(' ') << "ptr2int"
			<< "(0x" << &ptr2int << ") = 0x" << dec << ptr2int << endl;
		
		cout << left << setw(15) << setfill(' ') << "ptr2ptr"
			<< "(0x" << &ptr2ptr << ") = 0x" << dec <<ptr2ptr << endl;
		
		cout << left << setw(15) << setfill(' ') << "ptr2ptr2"
			<< "(0x" << &ptr2ptr2 << ") = 0x" << dec << ptr2ptr2 << endl;

		cout << "Press ENTER to print again." << endl;
		cout << endl;

		cout << "----------------------------------------------" << endl;
		cin.get();
	}
}

