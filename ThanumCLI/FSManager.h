#pragma once
#include <filesystem>

using namespace std;

class FSManager // FileSystemManager
{
public:
	FSManager();
	~FSManager();

	void turnTo(string path);
	vector<string> getAll();
	filesystem::path getCurrentPath();

private:
	filesystem::path path;
};

