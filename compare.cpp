/*******************************
Author:galaxy yr
LANG:C++
Created Time:2018年12月30日 星期日 21时20分01秒
*******************************/
#include<iostream>
#include<fstream>
#include<string>
#include<cstdio>
using namespace std;
const string name1="cmp1.txt";
const string name2="cmp2.txt";
ifstream f1(name1);
ifstream f2(name2);
int main()
{
        char c1,c2;
        int n=0;
        while(f1 and f2)
        {
                c1=f1.get();c2=f2.get();
                if(c1!=c2)
                {
                        cout<<"WRONG!!!\n";
                        cout<<"on line "<<n<<",read: "<<c1<<','<<c2<<endl;
                        return 0;
                }
                if(c1=='\n')n++;
        }
        cout<<"ALL RIGHT\n";
        return 0;
}
