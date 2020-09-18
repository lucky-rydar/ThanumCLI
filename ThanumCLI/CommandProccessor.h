#pragma once
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include "FSManager.h"

using namespace std;

class CommandProccessor
{
public:
	CommandProccessor();
	~CommandProccessor();

	void run_command(vector<string> command_data);
	
	void cd(vector<string> command_data);
	void ls(vector<string> command_data);
	void sys(vector<string> command_data);
	void help(vector<string> command_data);

	FSManager* getFSManager();
private:
	FSManager* fs_manager;
	fstream* help_file;
};

