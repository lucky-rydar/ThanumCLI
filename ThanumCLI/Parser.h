#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Parser
{
public:
	Parser();
	~Parser();

	vector<string> parse(string line);
private:

};

