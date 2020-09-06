#include "FSManager.h"

FSManager::FSManager()
{
	string cur_path_str = filesystem::current_path().string();
	regex back_to_front_slash("[\\\\]");
	string new_cur_path = regex_replace(cur_path_str.c_str(), back_to_front_slash, "/");
	this->path = new_cur_path;
	
}

FSManager::~FSManager()
{
}

void FSManager::turnTo(string path)
{
	if (path[0] == '/' || path.find(":") != string::npos) // if not relative
	{
		// added checking of the path
		if (filesystem::exists(filesystem::path(path)))
			this->path = path;
		else
			puts("No such file or directory");
	}
	else // else it is relative
	{
		string temp_path = this->path.string();
		if (*(this->path.string().end() - 1) == '/')
		{
			if(filesystem::exists(filesystem::path(temp_path + path)))
				this->path += string(path);
			else
				puts("No such file or directory");
		}
		else
		{
			if (filesystem::exists(filesystem::path(temp_path + "/" + path)))
				this->path += string("/" + path);
			else
				puts("No such file or directory");
		}
	}
}

void FSManager::turnUp()
{
	regex tmpl("(/[\\w\\d \\.]+\\/?)$");
	this->path = regex_replace(this->path.string(), tmpl, "");
}

vector<string> FSManager::getAllFiles()
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
