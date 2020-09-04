#pragma once
#include "Parser.h"
#include "FSManager.h"
#include "CommandProccessor.h"

class CommandLineInterface
{
public:
	CommandLineInterface();
	~CommandLineInterface();

	void getLine(string sufix = "$ ");
	void proccessLine();

private:
	FSManager* fs_manager;
	CommandProccessor* com_proc;

	vector<string> command_data;
	
};

