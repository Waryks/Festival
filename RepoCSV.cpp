#include "RepoCSV.h"
#include <fstream>
#include "Filme.h"
#include "Muzica.h"

RepoFileCSV::RepoFileCSV() : RepoFile()
{
}

RepoFileCSV::RepoFileCSV(string fileName) : RepoFile(fileName)
{
}

RepoFileCSV::~RepoFileCSV()
{
}

void RepoFileCSV::loadFromFile()
{
	ifstream f(this->fileName);
	if (f.is_open())
	{
		this->emptyRepo();
		string linie;
		string delim = ",";
		while (getline(f, linie))
		{
			if (linie.substr(0, 2) == "MU")
			{
				linie = linie.erase(0, 3);

				int pos = linie.find(delim);
				string loc = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string data = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int disponibil = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int ocupat = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string nume = linie.substr(0, pos);

				Muzica* mu = new Muzica(nume, loc, data, disponibil, ocupat);
				this->festival.push_back(mu);
			}
			else if (linie.substr(0, 2) == "FI")
			{
				linie = linie.erase(0, 3);

				int pos = linie.find(delim);
				string loc = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string data = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int disponibil = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int ocupat = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string titlu = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int nrActori = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string aux = linie.substr(0, pos);

				vector<string> actori;
				for (int i = 1; i <= nrActori; i++)
				{
					int gasit = aux.find(";");
					string act = aux.substr(0, gasit);
					aux = aux.erase(0, gasit + 1);
					actori[i] = act;
				}
				Filme* fi = new Filme(titlu, actori, loc, data, disponibil, ocupat);
				this->festival.push_back(fi);
			}
		}
		f.close();
	}
}

void RepoFileCSV::saveToFile()
{
	ofstream f(this->fileName);
	if (f.is_open())
	{
		for (Festival* elem : this->festival)
		{
			f << elem->toString(",") << endl;
		}
	}
}
