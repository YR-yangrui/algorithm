#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=1e5+100;
const int LG=20;
int f[maxn][LG+5];
int log[maxn];
int n,m;
int main()
{
	//https://www.luogu.org/problemnew/show/P3865#sub
	scanf("%d%d",&n,&m);
	log[0]=-1;
	for(int i=1;i<=n;i++)
		scanf("%d",&f[i][0]),log[i]=log[i>>1]+1;
	for(int j=1;j<=LG;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
	int x,y,z;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		z=log[y-x+1];
		printf("%d\n",max(f[x][z],f[y-(1<<z)+1][z]));
	}
	return 0;
}
