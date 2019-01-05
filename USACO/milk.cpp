/*
ID:galaxy_6
LANG:C++
TASK:milk
*/
#include<iostream>
#include<algorithm>
using namespace std;
struct cows{
	long long milk,price;
	bool operator<(const cows k)
	{ return price<k.price;}
	cows(){milk=price=0;};
	friend istream& operator>>(istream& os,cows& k)
	{
		os>>k.price;
		os>>k.milk;
		return os;
	}
};
int main()
{
        freopen("milk.in","r",stdin);
        freopen("milk.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cows s[m];
	for(int i=0;i<m;i++)cin>>s[i];
	sort(s,s+m);
	int need=0;
	int now=0;
	int money=0;
	while(need<n)
	{
		while(s[now].milk--&&need<n){need++;money+=s[now].price;} 
		now++;
	}
	cout<<money<<endl;
	return 0;
}
