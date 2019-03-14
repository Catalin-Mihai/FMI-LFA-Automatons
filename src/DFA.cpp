#include "DFA.h"

DFA::DFA()
{
    this->matrice = NULL;
}

DFA::~DFA()
{
    cout<<"called destructor DFA"<<endl;
}

bool DFA::CheckWord(string word)
{
    if(word.compare("L") == 0) //Lambda
    {
        if(this->isStareFinalaIndex(this->getStareInitialaIndex())) return true;
        else return false;
    }
    int stare = this->getStareInitialaIndex();
    int **matrice = this->getMatrice();
    for(unsigned int i = 0; i < word.length(); i++)
    {
        string s(1, word[i]);
        int simbIndex = this->getSimbolIndexByLitera(s);
        if(simbIndex == -1) return false;
        stare = matrice[stare][simbIndex];
        if(stare == -1) return false;
    }
    if(this->isStareFinalaIndex(stare)) return true;
    else return false;
}
