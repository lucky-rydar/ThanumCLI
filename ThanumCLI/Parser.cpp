#include "Parser.h"
#include "Parser.h"

Parser::Parser()
{
}

Parser::~Parser()
{
}

vector<string> Parser::parse_line(string line)
{
	line_corrector(line);
	regex templ("(?:([\\w\\d:/\\.]+)\\s?)(?:(.*)\\s?)?");
	cmatch found;
	vector<string> result;

	while (regex_match(line.c_str(), found, templ))
	{
		result.push_back(found[1]);
		if (line.size() > 2)
			line = found[2];
	}

	return result;
}

void Parser::line_corrector(string& line)
{
	regex double_dot(":");
	regex double_dot_slash(":/");
	
	if (!regex_search(line.c_str(), double_dot_slash))
	{
		line = regex_replace(line, double_dot, ":/");
		line += " ";
	}
}
