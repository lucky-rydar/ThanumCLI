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

}
