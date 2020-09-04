#pragma once
#include <filesystem>
#include <iostream>
#include <regex>

using namespace std;

class FSManager // FileSystemManager
{
public:
	FSManager();
	~FSManager();

	void turnTo(string path);
	void turnUp();

	vector<string> getAllFiles();
	filesystem::path getCurrentPath();

private:
	filesystem::path path;
};

