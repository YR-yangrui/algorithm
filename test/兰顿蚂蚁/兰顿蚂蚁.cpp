#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int maxn=1001;
bool mp[maxn][maxn];// 1 black 0 white
const int dx[4]={0,-1,0,1};
const int dy[4]={-1,0,1,0};
enum direction{left,up,right,down};
int x,y,dir;
void turn()
{
        if(mp[x][y]) dir=(dir+1)%4;
        else dir=(dir+3)%4;
        mp[x][y]=!mp[x][y];
        x+=dx[dir];y+=dy[dir];
}
void print(int n,int m)
{
        for(int i=1;i<=n;i++)
        {
                for(int j=1;j<=m;j++)
                {
                        if(i==x and j==y)
                        {
                                cout<<"\033[0m";
                                cout<<"@";
                                cout<<"\033[1m";
                                continue;
                        }
                        if(mp[i][j])cout<<'.';
                        else cout<<'*';
                }
                cout<<endl;
        }
}
const int repeat=1e6;
int main()
{
        int n,m;
        x=75;y=100;n=100,m=200;
        while(true)
        {
                system("clear");
                print(n,m);
                turn();
                for(int i=1;i<=repeat;i++);
        }
}
