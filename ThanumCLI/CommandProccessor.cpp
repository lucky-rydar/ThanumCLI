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
	if (command_data.size() >= 1)
	{
		if (command_data[0] == "cd")
			cd(command_data);
		else if (command_data[0] == "ls")
			ls(command_data);
		else if (command_data[0] == "sys")
			sys(command_data);
		else if (command_data[0] == "help")
			help(command_data);
	}
}

void CommandProccessor::cd(vector<string> command_data)
{
	if (command_data.size() > 2)
		puts("to many arguments to command \"cd\"");
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

void CommandProccessor::sys(vector<string> command_data)
{
	regex win_format("/");
	filesystem::path path = this->fs_manager->getCurrentPath().string();

	string op_and = " && ";
	string to_call = path.root_name().string() + op_and + string("cd ") + string(" ") + path.string() + op_and;

	for (size_t i = 1; i < command_data.size(); i++)	
		to_call += command_data[i] + " ";

	std::system(to_call.c_str());
}

void CommandProccessor::help(vector<string> command_data)
{
	help_file = new fstream("help.txt");

	stringstream ss;
	ss << help_file->rdbuf();
	string data = ss.str();
	cout << data << endl;

	delete help_file;
}

FSManager* CommandProccessor::getFSManager()
{
	return this->fs_manager;
}
