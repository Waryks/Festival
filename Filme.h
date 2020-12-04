#pragma once
#include "Festival.h"
#include <vector>

class Filme : public Festival{
private:
	string titlu;
	vector<string> actori;
public:
	Filme();
	Filme(string titlu, vector<string> actori, string loc, string data, int disponibil, int ocupat);
	Filme(const Filme& f);
	~Filme();
	Festival* clona();
	string getTitlu();
	vector<string> getActori();
	void setTitlu(string titlu);
	void setActori(vector<string> actori);
	Filme& operator=(const Filme& f);
	bool operator==(const Filme& f);
	string toString(string delim);
};