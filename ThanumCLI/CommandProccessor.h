#pragma once
#include <iostream>
#include <map>
#include <string>
#include "FSManager.h"

using namespace std;

class CommandProccessor
{
public:
	CommandProccessor();
	~CommandProccessor();

	void run_command(vector<string> command_data);

	FSManager* getFSManager();
private:
	FSManager* fs_manager;
};

