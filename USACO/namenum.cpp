/*
ID:galaxy_6
LANG:C++
TASK:namenum
*/
#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
using namespace std;
const char num[28]={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','0','7','7','8','8','8','8','8','8','0'};
string n,name;
int len;
bool check()
{
        if(name.length()!=len)return false;
        for(int i=0;i<len;i++)
                if(n[i]!=num[name[i]-'A'])
                        return false;
        return true;
}
const string name1="namenum.in";
const string name2="dict.txt";
ifstream f1(name1);
ifstream f2(name2);
bool ok;
int main()
{
        freopen("namenum.out","w",stdout);
        f1>>n;
        len=n.length();
        for(int i=1;i<=4734;i++)
        {
                f2>>name;
                if(check())
                {
                        cout<<name<<endl;
                        ok=1;
                }
        }
        if(!ok) cout<<"NONE\n";
        return 0;
}

