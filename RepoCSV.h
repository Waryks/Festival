#pragma once
#include "Repo.h"

class RepoFileCSV : public RepoFile {
public:
	RepoFileCSV();
	RepoFileCSV(string fileName);
	~RepoFileCSV();
	void loadFromFile();
	void saveToFile();
};