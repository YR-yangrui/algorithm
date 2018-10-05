#include<iostream>
using namespace std;
template<class k>
void Swap(k & a,k & b)
{
    k t=a;
    a=b;
    b=t;
}
class heap{
    public:
        enum modern{big,small};
	enum{maxn=1001000};
    private:
        
        int * ptr;
        int len;
        modern mo;
    public:
        heap();
        heap(const int* t,const int  n,const modern m=small);
        ~heap();
            heap(const heap & h);
        int get();
        void put(int a);
        int & operator[](int i);
        const int & operator[](int i)const;
        const int size(void)const;
};
//functions
heap::heap():len(0),mo(heap::small){ptr=new int[maxn];}
heap::heap(const int * t,const int n,const modern m){
    mo=m;
//	maxn=1e+6;
    ptr=new int[maxn];
    len=n+1;
    ptr[0]=0;
    for(int i=1;i<=len;i++)ptr[i]=t[i-1];
}
heap::~heap()
{
    delete[] ptr;
}
heap::heap(const heap & h)
{
    this->ptr=h.ptr;
    this->len=h.len;
    this->mo=h.mo;
}
int heap::get()
{
    int ans=ptr[1];
    ptr[1]=ptr[len--];
    int next,now=1;
    bool q=1;
    if(mo==big)q=0;
    while(now*2<=len)
    {
        next=now*2;
        if(q)
        {
            if(next+1<=len&&ptr[next]>ptr[next+1])next++;
            if(ptr[next]>=ptr[now])break;
        }
        else 
        {
            if(ptr[next]<ptr[next+1]&&next+1<=len)next++;
            if(ptr[next]<=ptr[now])break;
        }
            Swap(ptr[next],ptr[now]);
            now=next;
    }
    return ans;
}
void heap::put(int a)
{
    for(int i=1;i<=len;i++)if(ptr[i]==a)return;
    ptr[++len]=a;
    int next,now=len;
    bool q=1;
    if(mo==big)q=0;
    while(now>1)
    {
        next=now>>1;
        if(q)
        {
            if(ptr[now]>=ptr[next])break;
        }
        else 
        {
            if(ptr[next]<=ptr[now])break;
        }
            Swap(ptr[now],ptr[next]);
            now=next;
    }
}
int & heap::operator[](int i){return ptr[i];}
const int & heap::operator[](int i)const{return ptr[i];}
const int heap::size(void)const {return len;}
int main()
{
    heap h;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
	    h.put(i);
    for(int i=1;i<=n;i++)
	    cout<<h.get()<<endl;
    return 0;
}
