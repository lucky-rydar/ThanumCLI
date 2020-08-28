#pragma once
#include "Parser.h"
#include "FSManager.h"

class CommandLineInterface
{
public:
	CommandLineInterface();
	~CommandLineInterface();

	void getLine();

private:
	Parser* parser;
	FSManager *fs_manager;
};

