#pragma once
#include <string>

using namespace std;

class Festival {
protected:
	string loc, data;
	int disponibil, ocupat;
public:
	Festival();
	Festival(string loc,string data,int disponibil,int ocupat);
	Festival(const Festival& f);
	~Festival();
	virtual Festival* clona();
	string getLoc();
	string getData();
	int getDisponibil();
	int getOcupat();
	void setLoc(string loc);
	void setData(string data);
	void setDisponibil(int disponibil);
	void setOcupat(int ocupat);
	Festival& operator=(const Festival& f);
	bool operator==(const Festival& f);
	virtual string toString(string delim);
};