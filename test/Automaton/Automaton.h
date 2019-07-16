#ifndef _AUTOMATON_H_
#define _AUTOMATON_H_
#include<vector>
#include<iostream>
#include<string>
#include<cstring>
namespace AUTOMATON {
    class AUTOMATON{
        private:
            enum{MAX_STATE_NUM=100000};
            class transfer_function{
                private:
                std::string s;
                public:
                transfer_function(){}
                transfer_function(const std::string & t):s(t){}
                ~transfer_function(){}
                operator std::string()const { return s; }
                bool find(char c)const
                {
                    if(s.find(c))return true;
                    return false;
                }
                void add(const std::string k) {
                    s+=k;
                }
                void change(const std::string k) {
                    s=k;
                }
            };
            struct STATE{
                bool final_state;
                std::vector<STATE*>S;
                std::vector<transfer_function>T;
                STATE():final_state(0){}
                STATE(bool k):final_state(k){}
            }ST;
            std::vector<STATE>V;
        public:
            AUTOMATON(){} 
            ~AUTOMATON(){}
            friend std::ostream & operator<<(std::ostream & os,const AUTOMATON & AM);
    };
}
#endif
