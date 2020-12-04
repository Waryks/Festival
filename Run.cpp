#include <iostream>
#include "Repo.h"
#include "RepoTXT.h"
#include "RepoCSV.h"
#include "TestFestiv.h"
#include <string>

using namespace std;

int main()
{
    runAllTests();
    RepoFile* repoFile;
    cout << "TXT / CSV: ";
    string opt;
    getline(cin, opt);
    if (opt == "txt" || opt == "TXT")
    {
        repoFile = new RepoFileTXT("fisier.txt");
    }
    else
    {
        if (opt == "csv" || opt == "CSV")
        {
            repoFile = new RepoFileCSV("fisier.csv");
        }
    }
    return 0;
}
