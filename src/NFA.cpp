#include "NFA.h"

NFA::NFA()
{

}

NFA::~NFA()
{
    cout<<"called destrucor NFA"<<endl;
}

void NFA::AfiseazaMatrice()
{
    vector< vector< vector<int> > >::iterator it_stari;
    vector< vector<int> >::iterator it_simb;
    vector<int>::iterator it_elem;
    for(it_stari = this->tabel.begin(); it_stari != this->tabel.end(); it_stari++)
    {
        for(it_simb = it_stari->begin(); it_simb != it_stari->end(); it_simb++)
        {
            for(it_elem = it_simb->begin(); it_elem != it_simb->end(); it_elem++)
            {
                cout<<*it_elem<<" ";
            }
            cout<<"; ";
        }
        cout<<endl;
    }
}

void NFA::CitesteTranzitii()
{
//Construire matrice
    //Initializare cu tranzitii
    tabel.resize(this->stari.size());
    for(unsigned int i = 0; i < this->stari.size(); i++)
    {
        tabel[i].resize(this->simboluri.size());
    }

    for(unsigned int i = 0; i < this->tranzitii.size(); i++)
    {
        tabel[tranzitii[i].plecare][tranzitii[i].simb.index].push_back(tranzitii[i].destinatie);
    }

    vector< vector< vector<int> > >::iterator it_stari;
    vector< vector<int> >::iterator it_simb;
    for(it_stari = this->tabel.begin(); it_stari != this->tabel.end(); it_stari++)
    {
        for(it_simb = it_stari->begin(); it_simb != it_stari->end(); it_simb++)
        {
            if(it_simb->begin() == it_simb->end())
            {
                it_simb->push_back(-1);
            }
        }
    }
}

bool NFA::check(NFA &nfa, int stare_index, string word, unsigned int position)
{
    int simbIndex;
    if(position < word.length())
    {
        string s(1, word[position]);
        simbIndex = nfa.getSimbolIndexByLitera(s); //indexul simbolului de pe linie/sageata/tranzitie
        if(simbIndex == -1) return false;
        vector<int>::iterator it;
        for(it = nfa.tabel[stare_index][simbIndex].begin(); it != nfa.tabel[stare_index][simbIndex].end(); it++)
        {
            if(*it >= 0)//este tranzitie valida
            {
                if(check(nfa, *it, word, position+1)) return true;
            }
        }
        return false;
    }
    else if(nfa.isStareFinalaIndex(stare_index)) return true;
    return false;
}

bool NFA::CheckWord(string word)
{
    if(word.compare("L") == 0) //Lambda
    {
        if(this->isStareFinalaIndex(this->getStareInitialaIndex())) return true;
        else return false;
    }
    return check(*this, this->getStareInitialaIndex(), word, 0);
}
