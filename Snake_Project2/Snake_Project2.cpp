#include "pch.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Main_Functions.h"
#include "User_interface.h"
using namespace std;


int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);

	do {	
		menu_logo();
		music_Start();
		menu_StartScreen(1);	
	} while (shutDown == false);		

	return 0;
}
