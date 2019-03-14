#ifndef FA_H
#define FA_H

#include <string>
#include <istream>
#include <iostream>
#include <vector>

using namespace std;

class FA{

protected:

    struct simbol
    {
        string litera;
        int index;
    };

    struct tranzitie
    {
        simbol simb;
        int plecare;
        int destinatie;
    };

    struct stare
    {
        string litera;
        int index;
    };

    stare stare_initiala;
    vector<simbol> simboluri;
    vector<stare> stari;
    vector<stare> stari_finale;
    vector<tranzitie> tranzitii;
    int **matrice;
    virtual void AfiseazaMatrice();

public:
    FA();
    virtual ~FA();
    virtual bool CheckWord(string word) {return false;}
    friend istream &operator>>(istream &input, FA &fa);
    virtual void CitesteTranzitii();
    void Afiseaza();
    int **&getMatrice();
    int getStareIndexByLitera(string l);
    simbol getSimbolByLitera(string l);
    int getSimbolIndexByLitera(string l);
    int getStareInitialaIndex();
    bool isStareFinalaIndex(int index);
};

#endif // FA_H
