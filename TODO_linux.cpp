/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月05日 星期六 20时32分59秒
*******************************/
#include<iostream>
#include<cstdio>
#include<string>
#include<fstream>
#include<vector>
#include<cstdlib>
using namespace std;
istream fin(".TODO");
ofstream fout(".TODO",ios::app);
ifstream din(".DONE");
ofstream dout(".DONE",ios::app);
vector<string>V;
vector<string>D;
bool ok=1;
bool show_have_done=1;
string name;
void clear()
{
        while(cin.get()!='\n');
}
void show_list()
{
        cout<<"\033[1m有待完成:\n\033[32m";
        for(int i=0;i<V.size();i++)
        {
                cout<<i<<'.'<<V[i]<<' ';
                if((i+1)%4==0)cout<<endl;
        }
        cout<<"\033[0m";
        if(show_have_done)
        {
                cout<<endl;
                cout<<"\033[1m";
                cout<<"已完成:\n";
                cout<<"\033[31m";
                for(int i=0;i<D.size();i++)
                {
                        cout<<i<<'.'<<D[i]<<' ';
                        if((i+1)%4==0)
                                cout<<endl;
                }
                cout<<"\033[0m";
                cout<<endl;
        }
        return;
}
void save()
{
        fout.close();
        fout.open(".TODO");
        fout<<name<<endl;
        for(vector<string>::iterator it=V.begin();it!=V.end();it++)
                fout<<*it<<endl;
        dout.close();
        dout.open(".DONE");
        for(vector<string>::iterator it=D.begin();it!=D.end();it++)
                dout<<*it<<endl;
        ok=1;
        cout<<"保存成功\n";
        return;
}
void del()
{
        cout<<"请问您要删除任务还是已经完成了的任务？（输入 0取消 1删除任务 2删除完成了的任务）";
        int cho;
        cin>>cho;
        if(cho==0)return;
        cout<<"请问您要删除第几项任务？（输入-1取消）";
        int loc;
        cin>>loc;
        if(loc==-1)return;
        if(cho==1)
        {
                if(loc>=V.size()){cout<<"删除失败!\n";return;}
                V.erase(V.begin()+loc);
                cout<<"删除成功\n";
        }
        else if(cho==2)
        {
                if(loc>=D.size()){cout<<"删除失败!\n";return;}
                D.erase(D.begin()+loc);
                cout<<"删除成功\n";
        }
        ok=0;
        return;
}
void add()
{
        cout<<"请输入任务:";
        string t;
        cin>>t;
        V.push_back(t);
        cout<<"添加成功！\n";
        ok=0;
        return;
}
void quit()
{
        if(ok)exit(0);
        else 
        {
                cout<<"您已做了改但还未保存，确定要直接退出吗？ (y/n):";
                char ch;
                cin>>ch;
                if(ch=='n' or ch=='N')return;
        }
        exit(0);
}
void comp()
{
        cout<<"请输入您完成了的任务编号:";
        int loc;
        cin>>loc;
        if(!cin) { cout<<"非法输入！！！\n"; clear(); return; }
        if(loc>=V.size()){cout<<"非法输入!!!\n";return;}
        cout<<"确定完成了吗？(y/n) ";
        char ch;
        cin>>ch;
        if(ch=='y' or ch=='Y')
        {
                cout<<"恭喜！完成了一项任务！\n";
                D.push_back(V[loc]);
                V.erase(V.begin()+loc);
                ok=0;
        }
        return;
}
void menu()
{
        while(true)
        {
                cout<<name;
                cout<<",您想要做什么？\n";
                cout<<"A 保存 B 删除 C 查看 D退出 F完成 G添加\n";
                char ch;
                cin>>ch;
                while(cin.get()!='\n');
                if(ch=='l')ch='c';
                if(ch=='A' or ch=='a') save();
                else if(ch=='B' or ch=='b')del();
                else if(ch=='C' or ch=='c') show_list();
                else if(ch=='D' or ch=='d')quit();
                else if(ch=='F' or ch=='f')comp();
                else if(ch=='G' or ch=='g')add();
                else cout<<"非法操作！请重新输入!\n";
        }
}
int main()
{
        string t;
        if(!fin.is_open())
        {
                cout<<"初次使用，还未拥有计划表\n";
                cout<<"请输入您的名字:";
                cin>>name;
        }
        else
        {
                fin>>name;
                while(fin>>t)
                        V.push_back(t);
        }
        if(!din.is_open())cout<<"初次使用，还未拥有完成表\n";
        else while(din>>t) D.push_back(t);
        menu();

}
