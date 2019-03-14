#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <FA.h>
#include <DFA.h>
#include <NFA.h>
#include <LNFA.h>

using namespace std;

int main()
{
    /*ifstream f("input_DFA2.txt");
    DFA dfa;
    f>>dfa;
    int nr_cuv;
    f>>nr_cuv;
    dfa.Afiseaza();
    string cuvant;
    for(int i = 0; i < nr_cuv; i++)
    {
        f>>cuvant;
        bool t = dfa.CheckWord(cuvant);
        if(t == false) cout<<"Nu este bun cuvantul: "<<cuvant<<endl;
        else cout<<"Este bun cuvantul: "<<cuvant<<endl;
    }*/
    /*ifstream f("input_NFA.txt");
    NFA nfa;
    f>>nfa;
    int nr_cuv;
    f>>nr_cuv;
    nfa.Afiseaza();
    string cuvant;
    for(int i = 0; i < nr_cuv; i++)
    {
        f>>cuvant;
        bool t = nfa.CheckWord(cuvant);
        if(t == false) cout<<"Nu este bun cuvantul: "<<cuvant<<endl;
        else cout<<"Este bun cuvantul: "<<cuvant<<endl;
    }*/
    ifstream f("input_LNFA.txt");
    LNFA lnfa;
    f>>lnfa;
    int nr_cuv;
    f>>nr_cuv;
    lnfa.Afiseaza();
    string cuvant;
    for(int i = 0; i < nr_cuv; i++)
    {
        f>>cuvant;
        bool t = lnfa.CheckWord(cuvant);
        if(t == false) cout<<"Nu este bun cuvantul: "<<cuvant<<endl;
        else cout<<"Este bun cuvantul: "<<cuvant<<endl;
    }
    return 0;
}
