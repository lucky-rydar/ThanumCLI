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
	cin >> line;

	auto persing_result = parser->parse(line);
}
