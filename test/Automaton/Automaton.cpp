/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年06月09日 星期日 22时08分40秒
*******************************/
#include "Automaton.h"
using namespace _AUTOMATON;
AUTOMATON::AUTOMATON(){}
AUTOMATON::~AUTOMATON(){}
friend std::ostream & operator<<(std::ostream & os,const AUTOMATON & AM)
{
    for(int i=0;i<V.size();i++)
    {
        cout<<i<<":";
        cout<<"转移状态:";
        for(int j=0;j<V[i].S.size();j++)
            cout<<V[i].S[j]->id<<"
    }
}
