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
}
