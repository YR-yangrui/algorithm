#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int maxn=1e6+10;
int AC[maxn][26];
int bo[maxn];
int nxt[maxn];
bool bj[maxn];
int tot=1;
string s;
void make()
{
	int u=1;
	for(int i=0;i<s.size();i++)
	{
		int c=s[i]-'a';
		if(!AC[u][c])AC[u][c]=++tot;
		u=AC[u][c];
	}
		bo[u]++;
}
int que[maxn];
int q1,q2;
void bfs()
{
	for(int i=0;i<=25;i++)
		AC[0][i]=1;
	que[1]=1;
	nxt[1]=0;
	int q1=0,q2=1,u;
	while(q1<q2)
	{
		u=que[++q1];
		for(int i=0;i<=25;i++)
		{
			if(!AC[u][i])AC[u][i]=AC[nxt[u]][i];
			else
			{
				que[++q2]=AC[u][i];
				int v=nxt[u];
				nxt[AC[u][i]]=AC[v][i];
			}
		}
	}
}
int ans;
void find()
{
	int u=1;
	for(int i=0;i<s.size();i++)
	{
		int c=s[i]-'a';
		
		int k=AC[u][c];
		while(k>1 and !bj[k])
		{
			ans+=bo[k];
			bo[k]=0;
			bj[k]=1;
			k=nxt[k];
		}
		u=AC[u][c];
	}
	return;
}
int n;
int main()
{

         freopen("AC自动机.in","r",stdin);
         freopen("AC自动机.out","w",stdout);
	 scanf("%d",&n);
	 
	 while(n--)
	 {
		 cin>>s;
		 make();
	 }
	 bfs();
	 cin>>s;
	 find();
	 cout<<ans;
	 return 0;
}
