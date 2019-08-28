#include<cstring>
#include<string>
#include<cassert>
using namespace std;
class Hash{
	private :
		const static size_t maxn=100000;
		const static size_t b=99973;
		size_t tot;
		size_t* net;
		size_t* num;
		size_t* adj;
		size_t* stk;
		size_t top;
	public :
		Hash()
		{
			tot=top=0;
			net=new size_t[maxn]; num=new size_t[maxn]; adj=new size_t[maxn]; stk=new size_t[maxn];
			memset(net,0,sizeof net); memset(num,0,sizeof num); memset(adj,0,sizeof adj); memset(stk,0,sizeof stk);
	       	}
                ~Hash()
                {
                    delete [] net;
                    delete [] num;
                    delete [] adj;
                    delete [] stk;
                }
		void insert(size_t key)
		{
#ifdef find
			cout<<"start to insert\n";
#endif
			size_t h=key%b;
			size_t e=adj[h];
#ifdef find
			cout<<"h="<<h<<"  e="<<e<<endl;
#endif
			while(e)
			{
#ifdef find
				cout<<e<<' ';
#endif
				assert(e>=0);
				if(num[e]==key)return;
				e=net[e];
			}
#ifdef find
			cout<<endl<<" loop is ok \n";
#endif
			if(!adj[h])
			{
				assert(adj[h]>=0);
				stk[++top]=h;
				num[++tot]=key;adj[h]=tot;net[tot]=adj[h];
			}
#ifdef find
			cout<<"insert is ok\n";
#endif
			return;
		}
		bool query(size_t key)
		{
			size_t h=key%b;
			for(size_t e=adj[h];e;e=net[e])
				if(num[e]==key)return true;
			return false;
		}
		template<class T>
		size_t _hash(T* a )
		{
			size_t ans=0;
			static size_t base=131;
			while(size_t ch=(size_t)* a++)
				ans=ans*base+ch;
			return ans;
		}
		size_t _hash(const string & s)
		{
			size_t ans=0;
			static size_t base=131;
			for(size_t i=0;i<s.size();i++)
			{
				ans=ans*base+s[i]-'0';
			}
#ifdef find
			cout<<"hash is ok; ans="<<ans<<"\n";
#endif
			assert(ans>=0);
			return ans;
		}
};
