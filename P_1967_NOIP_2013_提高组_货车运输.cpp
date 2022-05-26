#include <bits/stdc++.h>
#define maxn 10010
#define maxm 50010
#define rd read()
using namespace std;
inline int read(){long long s=0,w=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();} while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;}
inline void write(int x) {if(x < 0) putchar('-'),x=-x;static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);}
int n,m,q,ans;
int fa[maxn],falca[maxn][30];
int dis[maxn][30],dep[maxn];
struct nod {int u,v,q;} mp[maxm];
basic_string<pair<int,int>> edge[maxn];
bool cmp(nod x,nod y) {return x.q > y.q;}
int find(int x) {return x == fa[x]?x:fa[x] = find(fa[x]);}
void dfs(int u,int f,int q)
{
    #define fa falca

    fa[u][0] = f; dis[u][0] = q; dep[u] = dep[f] + 1;
    for(int i = 1;i <= 15;i++)
        dis[u][i] = min(dis[u][i-1],dis[fa[u][i-1]][i-1]) , fa[u][i] = fa[fa[u][i-1]][i-1];
    for(auto x : edge[u])
        if(x.first != f) dfs(x.first,u,x.second);

    #undef fa
    return;
}
inline void LCA(int u,int v)
{
    #define fa falca

    ans = INT_MAX;
    if(dep[u] < dep[v]) swap(u,v);
    for(int i = 15;i >= 0;i--) if(dep[fa[u][i]] >= dep[v]) ans = min(ans,dis[u][i]),u = fa[u][i];
    if(u == v) {return;}
    for(int i = 15;i >= 0;i--) 
        if(fa[u][i] != fa[v][i])
        {
            ans = min(ans,min(dis[u][i],dis[v][i]));
            u = fa[u][i]; v = fa[v][i];
        }
    ans = min(ans,min(dis[u][0],dis[v][0]));

    #undef fa
    return;
}
void work(int x,int y)
{
    if(find(x) != find(y)) {cout << -1 << "\n";return;}
    LCA(x,y);
    write(ans); putchar('\n');
    return;
}
signed main()
{
    n = rd;m = rd;
    for(int i = 1;i <= m;i++)
    {
        mp[i].u = rd; mp[i].v = rd; mp[i].q = rd;
    }
    sort(mp+1,mp+1+m,cmp);
    for(int i = 1;i <= n;i++) fa[i] = i;
    for(int i = 1;i <= m;i++)
    {
        int fdu = find(mp[i].u),fdv = find(mp[i].v);
        if(fdu != fdv) 
        {
            //Connect
            fa[fdu] = fdv;
            edge[mp[i].u] += make_pair(mp[i].v,mp[i].q); edge[mp[i].v] += make_pair(mp[i].u,mp[i].q);
        }
    }
    for(int i = 1;i <= n;i++)
        if(fa[i] != i) dfs(i,i,INT_MAX);
    q = rd;
    for(int i = 1;i <= q;i++)
    {
        int x = rd,y = rd;
        work(x,y);
    }
}