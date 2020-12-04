#pragma once
#include "Festival.h"

using namespace std;

class Muzica : public Festival {
private:
	string artist;
public:
	Muzica();
	Muzica(string artist, string loc, string data, int disponibil, int ocupat);
	Muzica(const Muzica& m);
	~Muzica() {};
	Festival* clona();
	string getArtist();
	void setArtist(string artist);
	Muzica& operator=(const Muzica& m);
	bool operator==(const Muzica& m);
	string toString(string delim);
};