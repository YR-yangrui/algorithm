#include<bits/stdc++.h>
#define INFORMATION
using namespace std;
template<class T>
void shellsort(T * a,int n)
{
	int increment=n/2;
	while(increment>0)
	{
		for(int i=increment;i<=n;i++)
		{
			int x=a[i];
			int j;
			for(j=i-increment;j>=0 and x<a[j];j-=increment)
				a[j+increment]=a[j];
			a[j+increment]=x;
#ifdef INFORMATION
			cout<<"now the increment is "<<increment<<" and the array is:";
			for(int i=1;i<=n;i++)
				cout<<a[i]<<' ';
			cout<<endl;
#endif

		}
		increment>>=1;
	}
}
const int maxn=1e6;
int a[maxn];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	shellsort(a,n);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<' ';
	return 0;
}
