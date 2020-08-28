#include "FSManager.h"

FSManager::FSManager()
{
	this->path = filesystem::current_path();
}

FSManager::~FSManager()
{
}

void FSManager::turnTo(string path)
{
	this->path = filesystem::path(path);
	//TO DO: make relevant path
}

vector<string> FSManager::getAll()
{
	vector<string> res;
	filesystem::directory_iterator dir_iter(this->path);

	while (!dir_iter._At_end())
	{
		res.push_back(dir_iter->path().filename().string());
		dir_iter++;
	}
	
	return res;
}

filesystem::path FSManager::getCurrentPath()
{
	return this->path;
}
