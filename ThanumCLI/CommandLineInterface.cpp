#include "CommandLineInterface.h"

CommandLineInterface::CommandLineInterface()
{
	this->parser = new Parser();
	this->fs_manager = new FSManager();
}

CommandLineInterface::~CommandLineInterface()
{
	delete parser;
	delete fs_manager;
}

void CommandLineInterface::getLine()
{
	string line;
	cout << fs_manager->getCurrentPath().string() << "$ ";
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
