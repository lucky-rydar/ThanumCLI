﻿#include <iostream>
#include "CommandLineInterface.h"

using namespace std;

int main()
{
	CommandLineInterface cli;
	while (true)
	{
		cli.getLine();
		cli.proccessLine();
	}
}