#include "CommandLineInterface.h"

CommandLineInterface::CommandLineInterface()
{
	this->parser = new Parser();
	this->com_proc = new CommandProccessor();
	this->fs_manager = com_proc->getFSManager();
}

CommandLineInterface::~CommandLineInterface()
{
	delete parser;
	delete com_proc;
}

void CommandLineInterface::getLine(string sufix)
{
	string line;
	cout << fs_manager->getCurrentPath().string() << sufix;
	std::getline(cin, line);

	this->command_data = parser->parse(line);
	
}

void CommandLineInterface::proccessLine()
{
	for (int i = 0; i < command_data.size(); i++)
	{
		cout << command_data[i] << endl;
	}
	
	return;
}
