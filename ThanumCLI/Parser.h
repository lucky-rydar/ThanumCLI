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

	static vector<string> parse_line(string line);
private:
	static void line_corrector(string& line);
};

