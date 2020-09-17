#include "ConsoleConfigurator.h"

ConsoleConfigurator::ConsoleConfigurator()
{
}

void ConsoleConfigurator::changeConsoleName(string new_name)
{
	SetConsoleTitle(new_name.c_str());
}
