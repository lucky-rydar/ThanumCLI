#include "CommandLineInterface.h"

CommandLineInterface::CommandLineInterface()
{	
	this->com_proc = new CommandProccessor();
	this->fs_manager = com_proc->getFSManager(); // do not delete this
}

CommandLineInterface::~CommandLineInterface()
{
	delete com_proc;
}

void CommandLineInterface::getLine(string sufix)
{
	string line;
	cout << fs_manager->getCurrentPath().string() << sufix;
	std::getline(cin, line);

	this->command_data = Parser::parse_line(line);
}

void CommandLineInterface::proccessLine()
{
	com_proc->run_command(command_data);
	
	return;
}
