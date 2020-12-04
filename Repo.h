#pragma once
#include "Festival.h"
#include <vector>

using namespace std;

class RepoFile {
protected:
	vector<Festival*> festival;
	string fileName;
public:
	RepoFile();
	RepoFile(string fileName);
	~RepoFile();
	void setFileName(string fileName);

	vector<Festival*> getAll();
	int getSize();
	Festival* getFestival(int pos);
	void addFestival(Festival* p);
	void updateFestival(Festival* pVechi, Festival* pNou);
	void deleteFestival(Festival* p);

	void emptyRepo();

	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
};


