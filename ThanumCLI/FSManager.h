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
private:
	filesystem::path path;
};

