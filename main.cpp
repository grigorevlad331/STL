#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream inFile("input.txt");

    struct q
    {
        string name;
        string specialty;
    };

    int no_problems, no_doctors;

    inFile >> no_problems;

    vector<q> problems(no_problems);

    for (int i = 0; i < no_problems; i++)
    {
        inFile >> problems[i].name;
        inFile >> problems[i].specialty;
    }

    inFile >> no_doctors;

    vector<q> doctors(no_doctors);

    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> doctors[i].name;
        inFile >> doctors[i].specialty;
    }

    for (int i = 0; i < no_problems; i++)
    {
        int verif = 1;
        for (int j = 0; j < no_doctors && verif; j++)
        {
            if (doctors[j].specialty == problems[i].specialty) verif = 0;
        }

        if (verif) cout << problems[i].name << " " << "Respins" << endl;
        else cout << problems[i].name << " " << "Acceptat" << endl;
    }

    return 0;
}