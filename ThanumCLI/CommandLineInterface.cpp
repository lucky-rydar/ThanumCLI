#include "CommandLineInterface.h"

CommandLineInterface::CommandLineInterface()
{
	this->parser = new Parser();
}

CommandLineInterface::~CommandLineInterface()
{
	delete parser;
}

void CommandLineInterface::getLine()
{

}
