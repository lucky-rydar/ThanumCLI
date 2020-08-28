#pragma once
#include "Parser.h"

class CommandLineInterface
{
public:
	CommandLineInterface();
	~CommandLineInterface();

	void getLine();

private:
	Parser* parser;
};

