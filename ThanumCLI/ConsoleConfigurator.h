#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class ConsoleConfigurator
{
public:
	ConsoleConfigurator();
	void changeConsoleName(string new_name);

private:
	wstring current_console_name;
};

