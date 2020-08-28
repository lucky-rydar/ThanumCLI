#include <iostream>
#include "CommandLineInterface.h"

using namespace std;

int main()
{
    FSManager fsm;
    auto files = fsm.getAll();

	for (size_t i = 0; i < files.size(); i++)
	{
		cout << files[i] << endl;
	}
	
}