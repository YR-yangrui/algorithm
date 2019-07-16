/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年06月09日 星期日 21时11分30秒
*******************************/
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
        freopen("t.in","r",stdin);
        freopen("t.out","w",stdout);
        int * a,*b;
        b=new int ;
        *b=3;
        a=b;
        cout<<a<<' '<<b<<endl;
        cout<<*a<<' '<<*b;
}
