#pragma once
#include <iostream>
#include <windows.h>

class System
{
public:
	static void Init()
	{
		/*setlocale(LC_ALL, "rus");*/
		setlocale(LC_ALL, "en_US.UTF - 8");
		HWND hWindowConsole = GetConsoleWindow();
		RECT r;
		GetWindowRect(hWindowConsole, &r); //сохраняет текущие размеры консоли
		MoveWindow(hWindowConsole, r.left, r.top, 800, 700, TRUE);
	}
	
};







