/*
ID:galaxy_6
LANG:C++
TASK:pprime
*/
#include <iostream>
#include <cmath>
using namespace std;
int x,y;
bool isprime(int x)
{
	for(int i=2;i<=sqrt(x);i++)
	if(x%i==0)return 0;
	return 1;
}
int pz;
void hwzsb()
{
        if(y>=5 and x<=5){cout<<5<<endl;}
        if(y>=7 and x<=7){cout<<7<<endl;}
        if(y>=11 and x<=11){cout<<11<<endl;}
	if(y<=100)return;
	for(int d1=1;d1<=9;d1+=2)
	for(int d2=0;d2<=9;d2++)
	{
		pz=100*d1+10*d2+d1;
                if(pz<x)continue;
                if(pz>y)break;
		if(isprime(pz))cout<<pz<<endl;
	}
	if(y<=10000)return;
	for(int d1=1;d1<=9;d1+=2)
	for(int d2=0;d2<=9;d2++)
	for(int d3=0;d3<=9;d3++)
	{
		pz=10000*d1+1000*d2+100*d3+10*d2+d1;
                if(pz<x)continue;
                if(pz>y)break;
                if(pz>y)break;
		if(isprime(pz))cout<<pz<<endl;
	}
	if(y<=1000000)return;
	for(int d1=1;d1<=9;d1+=2)
	for(int d2=0;d2<=9;d2++)
	for(int d3=0;d3<=9;d3++)
	for(int d4=0;d4<=9;d4++)
	{
		pz=d1*1000000+d2*100000+d3*10000+d4*1000+d3*100+d2*10+d1;
                if(pz<x)continue;
                if(pz>y)break;
                if(pz>y)break;
		if(isprime(pz))cout<<pz<<endl;
	}
}
int main()
{
       freopen("pprime.in","r",stdin);
       freopen("pprime.out","w",stdout);
	cin>>x>>y;
	hwzsb();
	return 0;
}
