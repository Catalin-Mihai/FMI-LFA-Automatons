#ifndef LNFA_H
#define LNFA_H

#include "NFA.h"

class LNFA: public NFA
{
    public:
        LNFA();
        ~LNFA();
        bool CheckWord(string word);

    private:
        //vector< vector< vector<int> > > tabel; //nu pot folosi numele de matrice din FA...
        bool check(LNFA &lnfa, int stare_index, string word, unsigned int position);
        int getLambdaSimbIndex();
};

#endif // LNFA_H
