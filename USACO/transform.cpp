/*
ID:galaxy_6
LANG:C++
TASK:transform
*/
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=15;
int n;
struct matrix{
        enum{size=15};
        char s[maxn][maxn];
        char* operator[](int i){return s[i];}
        friend  bool operator==(matrix s,matrix k)
        {
                for(int i=1;i<=n;i++)
                        for(int j=1;j<=n;j++)
                                if(s[i][j]!=k[i][j])
                                        return false;
                return true;
        }
}fin,s;
void print(matrix & s)
{
        for(int i=1;i<=n;i++)
        {
                for(int j=1;j<=n;j++)
                        cout<<s[i][j];
                cout<<endl;
        }
}
matrix turn_90(matrix s)
{
        matrix t;
        for(int i=1;i<=n;i++)
        {
                for(int j=1;j<=n;j++)
                        t[j][n-i+1]=s[i][j];
        }
        return t;
}
matrix turn_180(matrix s) { return turn_90(turn_90(s)); }
matrix turn_270(matrix s) { return turn_180(turn_90(s)); }
matrix reflect(matrix s)
{
        matrix t;
        for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                        t[i][j]=s[i][n-j+1];
        return t;
}
int step[100],top;
int main()
{
        freopen("transform.in","r",stdin);
        freopen("transform.out","w",stdout);
        cin>>n;
        for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                        cin>>s[i][j];
        for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                        cin>>fin[i][j];
        if(turn_90(s)==fin){cout<<1<<endl;return 0;}
        if(turn_180(s)==fin){cout<<2<<endl;return 0;}
        if(turn_270(s)==fin){cout<<3<<endl;return 0;}
        s=reflect(s);
        if(s==fin){cout<<4<<endl;return 0;}
        if(turn_90(s)==fin){cout<<5<<endl;return 0;}
        if(turn_180(s)==fin){cout<<5<<endl;return 0;}
        if(turn_270(s)==fin){cout<<5<<endl;return 0;}
        s=reflect(s);
        if(s==fin){cout<<6<<endl;return 0;}
        cout<<7<<endl;
        return 0;
}
