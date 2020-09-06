#include <iostream>
#include "CommandLineInterface.h"
//#include "ColoredPrinter.h"
using namespace std;

int main()
{
	CommandLineInterface cli;
	while (true)
	{
		cli.getLine();
		cli.proccessLine();
	}
	
	
	/*ColoredPrinter printer;
	cout << "Hello World!" << endl;
	printer.print("hello\n", Color::White, Color::Gray);
	printer.print("I am Misha\n", Color::Black, Color::Red);*/
}