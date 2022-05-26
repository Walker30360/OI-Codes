#include <bits/stdc++.h>
#define maxn 200010
#define mod
#define rd read()
//#define int long long
//#define nosync
typedef long long ll;
typedef long double ld;
using namespace std;
//Quick Read and Write
namespace IO{
    inline int read(){
        int x=0;int f=1;char ch;
        while((ch=getchar())<'0'||x>'9')if(ch=='-')f=-1;
        while(ch>='0'&&ch<='9'){x=((x<<1)+(x<<3)+(ch^48)),ch=getchar();}
        return x*f;
    }
    void write(char x){putchar(x);}
    void write(const char *x){for(;*x;++x)putchar(*x);}
    void write(char *x){for(;*x;++x)putchar(*x);}
    void write(signed x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar('0'+x-x/10*10);}
    void write(long long x){
        if(x<0)putchar('-'),x=-x;
        if(x>9)write(x/10);
        putchar('0'+x-x/10*10);
    }
    void write(double x){printf("%0.2lf",x);}
    void write(string s){for(char c:s)putchar(c);}
    template<typename type1,typename type2,typename ...typen>
    void write(type1 a1,type2 a2,typen ...an){
        write(a1);
        write(a2,an...);
    }
}using namespace IO;
//init structs
struct nod
{
	int start,to,len;
	nod(){}	
	nod(int x,int y,int z){start = x,to = y,len = z;}
	void readnod(){start = rd,to = rd,len = rd;}
};
//init numbers
int n,m,s,t,sel,sum;
int fa[maxn];
nod edge[maxn];
//init functions
bool cmp(nod x,nod y) {return x.len < y.len;}
int getfa(int x) {return fa[x] == x?x:fa[x] = getfa(fa[x]);}
void mix(int x,int y)
{
    int fx = getfa(x),fy = getfa(y);
    if(fx != fy) fa[fx] = fy;
}
//main
signed main()
{
    //nosync
	#ifdef nosync
    ios::sync_with_stdio(false);
    cin.tie(0);
    #endif
    //code
	n = rd,m = rd,s = rd,t = rd;
    for(int i = 1;i <= m;i++)
        edge[i].readnod();
	sort(edge+1,edge+1+m,cmp);
    for(int i = 1;i <= n;i++) fa[i] = i;
    for(int i = 1;i <= m && sel <= n-1;i++)
    {
        if(getfa(edge[i].start) != getfa(edge[i].to))
            mix(edge[i].start,edge[i].to),sel++;
        if(getfa(s) == getfa(t))
            write(edge[i].len),exit(0);
    }

	return 0;
}