#include "CommandProccessor.h"

CommandProccessor::CommandProccessor()
{
	this->fs_manager = new FSManager();
}

CommandProccessor::~CommandProccessor()
{
	delete fs_manager;
}

void CommandProccessor::run(vector<string> command_data)
{

}

FSManager* CommandProccessor::getFSManager()
{
	return this->fs_manager;
}
