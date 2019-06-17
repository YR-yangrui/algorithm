/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年06月17日 星期一 21时32分01秒
*******************************/
#include<iostream>
#include<cstdio>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<string>
std::ifstream fin("word.txt");
const int Max_Size=5000;
std::string s[Max_Size];
int cnt;
void read()
{
    cnt=1;
    while(fin>>s[cnt])++cnt;
    --cnt;
    fin.clear();
}
void Random_Selection(int rp)
{
    while(rp--)
    {
        int choice=rand()%cnt+1;
        std::cout<<s[choice]<<std::endl;
        char ch=std::cin.get();
        if(ch=='?')
        {
            //std::string call="sdcv -u 朗道英汉字典5.0 ";
            std::string call="translate ";
            call+=s[choice];
            std::system(call.c_str());
        }
        while(std::cin.get()!='\n')continue;
    }
}
int main()
{
        srand(time(0));
        read();
        std::cout<<"请输入抽查次数:";
        int rp;
        std::cin>>rp;
        while(std::cin.get()!='\n')continue;
        std::cout<<"开始抽查！（输入q退出)\n";
        Random_Selection(rp);
        return 0;
}
