#include "LNFA.h"

LNFA::LNFA()
{
    //ctor
}

LNFA::~LNFA()
{
    cout<<"Called destuctor LNFA"<<endl;
}

int LNFA::getLambdaSimbIndex()
{
    return this->getSimbolIndexByLitera("L");
}

bool LNFA::check(LNFA &lnfa, int stare_index, string word, unsigned int position)
{
    int simbIndex;
    if(position < word.length())
    {
        string s(1, word[position]);
        simbIndex = lnfa.getSimbolIndexByLitera(s); //indexul simbolului de pe linie/sageata/tranzitie
        if(simbIndex == -1) return false;
        vector<int>::iterator it;
        for(it = lnfa.tabel[stare_index][simbIndex].begin(); it != lnfa.tabel[stare_index][simbIndex].end(); it++)
        {
            if(*it >= 0)//este tranzitie valida
            {
                if(check(lnfa, *it, word, position+1)) return true;
            }
        }
        int lambda_simbIndex = lnfa.getLambdaSimbIndex();
        if(lambda_simbIndex == -1) return false;
        //cout<<lambda_simbIndex<<endl;
        for(it = lnfa.tabel[stare_index][lambda_simbIndex].begin(); it != lnfa.tabel[stare_index][lambda_simbIndex].end(); it++)
        {
            if(*it >= 0)//este tranzitie valida
            {
                //cout<<*it<<endl;
                if(check(lnfa, *it, word, position)) return true;
            }
        }
        return false;
    }
    else if(lnfa.isStareFinalaIndex(stare_index)) return true;
    return false;
}

bool LNFA::CheckWord(string word)
{
    return check(*this, this->getStareInitialaIndex(), word, 0);
}

