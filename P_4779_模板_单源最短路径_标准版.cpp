#include <bits/stdc++.h>
#define maxn 100010
#define sp ' '
#define mod
#define rd read()
#define INT_MX (1ll << 31)-1
// #define int long long
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
struct pt
{
    int u,v,w,nxt;
};
struct nod
{
	int to,d;
	bool operator<(const nod &t) const {return d > t.d;}
};
//init numbers
int n,m,s,tot;
int head[maxn],dis[maxn],vis[maxn];
pt edge[maxn * 10];
priority_queue<nod> que;
//init functions
void add(int u,int v,int w) {edge[++tot] = pt{u,v,w,head[u]}; head[u] = tot;}
void dijkstra()
{
    for(int i = 1;i <= n;i++) dis[i] = INT_MX;
    dis[s] = 0;
    que.push(nod{s,0});
    while(!que.empty())
    {
        auto top = que.top(); que.pop();
        if(vis[top.to]) continue;
        int to = top.to; vis[to] = 1;
        for(int i = head[to];i;i = edge[i].nxt)
        {
            int v = edge[i].v;
            if(dis[v] > dis[to] + edge[i].w)
            {
                dis[v] = dis[to] + edge[i].w;
                que.push(nod{v,dis[v]});
            }
        }
    }
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
	n = rd,m = rd,s = rd;
	int u,v,w;
	for(int i = 1;i <= m;i++) u = rd,v = rd,w = rd,add(u,v,w);
    dijkstra(); 
    for(int i = 1;i <= n;i++) write(dis[i],sp);
	return 0;
}