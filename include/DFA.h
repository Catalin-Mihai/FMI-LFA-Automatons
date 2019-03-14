#ifndef DFA_H
#define DFA_H

#include "FA.h"

class DFA: public FA
{
    public:
        DFA();
        ~DFA();
        bool CheckWord(string word);
    protected:

    private:
};

#endif // DFA_H
