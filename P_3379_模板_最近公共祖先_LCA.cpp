#include <bits/stdc++.h>
#define rd read()
#define maxn 500010
using namespace std;
int n,m,s;
int lg[maxn];
inline int read(){long long s=0,w=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();} while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;}
inline void write(int x) {if(x < 0) putchar('-'),x=-x;static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);}
int fa[maxn][30],dep[maxn];
basic_string<int> tr[maxn];
void dfs(int p,int f)
{
    fa[p][0] = f; dep[p] = dep[f] + 1;
    for(int i = 1;i <= 20;i++)
        fa[p][i] = fa[fa[p][i-1]][i-1];
    for(int i : tr[p])
    {
        if(i != f) dfs(i,p);
    }
    return;
}
int LCA(int x,int y)
{
    if(dep[x] < dep[y]) swap(x,y);
    while(dep[x] != dep[y]) x = fa[x][lg[dep[x] - dep[y]] - 1];
    if(x == y) return x;
    for(int k = 20;k >= 0;k--)
        if(fa[x][k] != fa[y][k]) x = fa[x][k],y = fa[y][k];
    return fa[x][0];
}
signed main()
{
    n = rd;m = rd;s = rd;
    for(int i = 1;i < n;i++)
    {
        int x = rd,y = rd;
        tr[x] += y;tr[y] += x;
    }
    for(int i = 1;i <= n;i++)
    {
        lg[i] = lg[i-1];
        if((1 << lg[i-1]) == i) lg[i]++;
    }	
    dfs(s,0); //init
    for(int i = 1;i <= m;i++)
    {
        int x = rd,y = rd;
        write(LCA(x,y));putchar('\n');
    }
    
    return 0;
}