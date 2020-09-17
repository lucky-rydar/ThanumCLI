#include "CommandLineInterface.h"
#include "TextConvertor.h"

CommandLineInterface::CommandLineInterface()
{	
	this->console = new ConsoleConfigurator();
	console->changeConsoleName("Thanum");
	
	std::setlocale(LC_ALL, "Russian");
	std::system("cls");

	this->com_proc = new CommandProccessor();
	this->fs_manager = com_proc->getFSManager(); // do not delete this
}

CommandLineInterface::~CommandLineInterface()
{
	delete com_proc;
	delete console;
}

void CommandLineInterface::getLine(string sufix)
{
	string line;
	cout << TextConvertor::coloredBy(fs_manager->getCurrentPath().string(), Color::BrightBlue) << TextConvertor::coloredBy(sufix, Color::BrightWhite);
	std::getline(cin, line);

	this->command_data = Parser::parse_line(line);
}

void CommandLineInterface::proccessLine()
{
	com_proc->run_command(command_data);
	
	return;
}
