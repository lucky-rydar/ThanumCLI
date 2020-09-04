#include "CommandProccessor.h"

CommandProccessor::CommandProccessor()
{
	this->fs_manager = new FSManager();
}

CommandProccessor::~CommandProccessor()
{
	delete fs_manager;
}

void CommandProccessor::run_command(vector<string> command_data)
{
	if (command_data[0] == "cd")
		cd(command_data);
	else if (command_data[0] == "ls")
		ls(command_data);
}

void CommandProccessor::cd(vector<string> command_data)
{
	if (command_data.size() > 2)
		puts("to many arguments in command \"cd\"");
	else
	{
		if (command_data[1] == "..")
			this->fs_manager->turnUp();
		else
			this->fs_manager->turnTo(command_data[1]);
	}
		
}

void CommandProccessor::ls(vector<string> command_data)
{
	if (command_data.size() > 1)
		puts("To many arguments");
	else
	{
		auto files = this->fs_manager->getAllFiles();
		for (size_t i = 0; i < files.size(); i++)
		{
			cout << files[i] << endl;
		}
	}
}

FSManager* CommandProccessor::getFSManager()
{
	return this->fs_manager;
}
