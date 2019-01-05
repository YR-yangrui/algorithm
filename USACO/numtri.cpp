/*
ID:galaxy_6
LANG:C++
TASK:numtri
*/
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1001;
int r;
int w[maxn][maxn];
int main()
{
       freopen("numtri.in","r",stdin);
       freopen("numtri.out","w",stdout);
	cin>>r;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=i;j++)
			cin>>w[i][j];
	for(int i=r-1;i>=1;i--)
		for(int j=1;j<=i;j++)
			w[i][j]+=max(w[i+1][j+1],w[i+1][j]);
	cout<<w[1][1]<<endl;
	return 0;
}
