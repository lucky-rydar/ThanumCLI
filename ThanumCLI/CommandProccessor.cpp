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
		else if(command_data[0] == "sys")
			sys(command_data);
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
	string my_path = this->fs_manager->getCurrentPath().string();
	filesystem::path win_path = regex_replace(my_path, win_format, "\\");

	regex file("\\w*\\.\\w+");
	for (size_t i = 0; i < command_data.size(); i++)
	{
		if (regex_search(command_data[i], file))
		{
			struct stat buffer;
			
			if (win_path.string()[win_path.string().size() - 1] != '\\')
			{
				if (stat((win_path.string() + "\\" + command_data[i]).c_str(), &buffer) == 0)
					command_data[i] = win_path.string() + "\\" + command_data[i];
			}
			else
			{
				if (stat((win_path.string() + command_data[i]).c_str(), &buffer) == 0)
					command_data[i] = win_path.string() + command_data[i];
			}
		}
			
	}

	string to_call;
	string buff;

	for (size_t i = 1; i < command_data.size(); i++)
	{
		
		to_call += command_data[i] + " ";
	}
	std::system(to_call.c_str());
}

FSManager* CommandProccessor::getFSManager()
{
	return this->fs_manager;
}
