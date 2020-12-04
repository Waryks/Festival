#include "TestFestiv.h"
#include "Festival.h"
#include "Filme.h"
#include "Muzica.h"
#include "RepoCSV.h"
#include "RepoTXT.h"
#include "Repo.h"
#include <assert.h>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

void runAllTests()
{
	
	string date, name, place;
	date = "2020";
	name = "Ana";
	place = "Cluj";

	Muzica a(name, date, place, 150, 100);
	assert(a.getArtist()==name);

	a.setLoc("Mangalia");
	assert(a.getLoc()=="Mangalia");

	vector<string> actori = { "John", "Johnny", "Johnson" };

	Filme f(name, actori, place,date, 150, 100);

	assert(f.getData() == "2020");
	assert(f.getOcupat() == 100);
	assert(f.getActori().size() == 3);

	vector<string> newactori = { "John", "Johnny", "Johnson", "Johnnyonson"};
	f.setActori(newactori);
	assert(f.getActori().size() == 4);

	RepoFile* repoFile = new RepoFileTXT();
	assert(repoFile->getSize() == 0);

	Muzica* a1 = new Muzica("John", "2222", "Oradea", 200, 150);
	Muzica* a2 = new Muzica("John", "2222", "Oradea", 200, 150);

	repoFile->addFestival(a1);
	repoFile->addFestival(a2);
	vector<Festival* > artists = repoFile->getAll();
	assert(artists.size() == 2);

	repoFile->deleteFestival(a1);
	artists = repoFile->getAll();
	assert(artists.size() == 1);
	repoFile->deleteFestival(a2);
	assert(repoFile->getSize() == 0);

	RepoFile* RepoTXTFile = new RepoFileTXT("testFestivOut.txt"); 
	RepoTXTFile->emptyRepo();
	assert(RepoTXTFile->getSize() == 0);

	Muzica* aa1 = new Muzica("John", "2222", "Oradea", 200, 150);
	Muzica* aa2 = new Muzica("John", "2222", "Oradea", 200, 150);

	RepoTXTFile->addFestival(aa1);
	RepoTXTFile->addFestival(aa2);
	vector<Festival*> artists1 = RepoTXTFile->getAll();
	assert(artists1.size() == 2);

	RepoFile* RepoTXTFile1 = new RepoFileTXT("testFestivOut.txt");
	RepoTXTFile1->emptyRepo();
	Filme* f1 = new Filme("ABC", { "a","b" }, "2020", "Oradea", 200, 150);
	Filme* f2 = new Filme("ABC", { "a","b" }, "2020", "Oradea", 200, 150);
	RepoTXTFile1->addFestival(f1);
	RepoTXTFile1->addFestival(f2);
	vector<Festival*> films = RepoTXTFile1->getAll();
	assert(RepoTXTFile1->getSize() == films.size());
	
	RepoFile* RepoCSVFile = new RepoFileCSV("testFestivOut.csv");
	RepoCSVFile->emptyRepo();
	assert(RepoCSVFile->getSize() == 0);

	Muzica* aaa1 = new Muzica("John", "2020", "Oradea", 200, 150);
	Muzica* aaa2 = new Muzica("John", "2020", "Oradea", 200, 150);

	RepoCSVFile->addFestival(aaa1);
	RepoCSVFile->addFestival(aaa2);
	vector<Festival*> artists2 = RepoCSVFile->getAll();
	assert(artists2.size() == 2);

	RepoFile* RepoCSVFile1 = new RepoFileCSV("testFestivOut.csv");
	RepoCSVFile1->emptyRepo();
	Filme* ff1 = new Filme("ABC", { "a","b" }, "2020", "Oradea", 200, 150);
	Filme* ff2 = new Filme("ABC", { "a","b" }, "2020", "Oradea", 200, 150);
	RepoCSVFile1->addFestival(ff1);
	RepoCSVFile1->addFestival(ff2);
	vector<Festival*> films1 = RepoCSVFile1->getAll();
	assert(RepoCSVFile1->getSize() == films1.size());
}