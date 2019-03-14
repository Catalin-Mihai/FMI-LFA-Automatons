#ifndef NFA_H
#define NFA_H

#include "FA.h"

class NFA: public FA
{
    public:
        NFA();
        ~NFA();
        virtual bool CheckWord(string word);
        void CitesteTranzitii();

    protected:
        vector< vector< vector<int> > > tabel; //nu pot folosi numele de matrice din FA...
        virtual bool check(NFA &nfa, int stare_index, string word, unsigned int position);
        void AfiseazaMatrice();
};

#endif // NFA_H
