#pragma once
#include <Windows.h>
#include <iostream>

using namespace std;

enum Color
{

};

class ColoredPrint
{
public:
	static void test_color()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		// you can loop k higher to see more color choices
		for (int k = 1; k < 255; k++)
		{
			// pick the colorattribute k you want
			SetConsoleTextAttribute(hConsole, k);
			cout << k << " I want to be nice today!" << endl;
		}
	}
private:

};

