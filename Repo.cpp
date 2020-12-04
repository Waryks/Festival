#include "Repo.h"

RepoFile::RepoFile()
{
}

RepoFile::RepoFile(string fileName)
{
	this->fileName = fileName;
}

RepoFile::~RepoFile()
{
}

void RepoFile::setFileName(string fileName)
{
	this->fileName = fileName;
}

vector<Festival*> RepoFile::getAll()
{
	return this->festival;
}

int RepoFile::getSize()
{
	return this->festival.size();
}

Festival* RepoFile::getFestival(int pos)
{
	if (pos >= 0 && pos < this->getSize())
	{
		return this->festival[pos]->clona();
	}
	return new Festival();
}

void RepoFile::addFestival(Festival* f)
{
	this->festival.push_back(f->clona());
	this->saveToFile();
}

void RepoFile::updateFestival(Festival* pVechi, Festival* pNou)
{
	for (int i = 0; i < this->festival.size(); i++)
	{
		if (*(this->getFestival(i)) == *pVechi)
		{
			delete this->festival[i];
			this->festival[i] = pNou->clona();
			this->saveToFile();
			return;
		}
	}
}

void RepoFile::deleteFestival(Festival* p)
{
	for (int i = 0; i < this->festival.size(); i++)
	{
		if (**(this->festival.begin() + i) == *p)
		{
			delete this->festival[i];
			this->festival.erase(this->festival.begin() + i);
			this->saveToFile();
			return;
		}
	}
}

void RepoFile::emptyRepo()
{
	for (int i = 0; i < this->getSize(); i++)
	{
		delete this->festival[i];
	}
	this->festival.clear();
}

