// Problem: P3371 【模板】单源最短路径（弱化版）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3371
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define maxn 10010
#define mod
#define INT_MX (1ll<<31)-1
#define rd read()
#define ps putchar(' ')
#define pn putchar('\n')
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
	int to,d;
	bool operator<(const nod &t) const {return d > t.d;}
};
//init numbers
int n,m,s;
basic_string<nod> edge[maxn];
int head,tail;
int que[maxn * 10],dis[maxn],vis[maxn];
//init functions
inline void ins(int x) {vis[x] = 1; que[++tail] = x;return;}
void SPFA(int s)
{
	for(int i = 1;i <= n;i++) dis[i] = INT_MX;
	dis[s] = 0; head = 1,tail = 0;
	ins(s);
	while(head <= tail)
	{
		int top = que[head++]; vis[top] = 0;
		for(auto next : edge[top])
		{
			if(dis[next.to] > dis[top] + next.d)
			{
				dis[next.to] = dis[top] + next.d;
				if(!vis[next.to]) ins(next.to);
			}
		}
	}
	for(int i = 1;i <= n;i++) write(dis[i]),ps;
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
	n = rd,m = rd,s = 1;
	int u,v,w;
	for(int i = 1;i <= m;i++) u = rd,v = rd,w = rd,edge[u] += nod{v,w};
	SPFA(s);

	return 0;
}