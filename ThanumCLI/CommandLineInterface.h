#pragma once
#include "Parser.h"
#include "FSManager.h"

class CommandLineInterface
{
public:
	CommandLineInterface();
	~CommandLineInterface();

	void getLine();
	void proccessLine();

private:
	
	
	vector<string> command_data;
	Parser* parser;
	FSManager *fs_manager;
};

