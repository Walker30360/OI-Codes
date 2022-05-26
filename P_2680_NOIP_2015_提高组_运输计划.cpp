#include <bits/stdc++.h>
#define rd read()
#define maxn 300010 << 2
using namespace std;
inline int read(){long long s=0,w=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();} while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;}
inline void write(int x) {if(x < 0) putchar('-'),x=-x;static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);}
int n,m,tot;
int all;
int dep[maxn],fa[maxn][30],dis[maxn];
int head[maxn];
int vis[maxn];
int gt[maxn],cnt; //dfs序维护
int tmp[maxn]; //tmp[i] 记录i这个点通向父亲的边被遍历的次数
struct nod
{
    int to,next,quan;
}edge[maxn];
struct nodx
{
    int from,to;
    int lca,dis;
}road[maxn];
void add(int x,int y,int quan)
{
    edge[++tot].to = y; edge[tot].next = head[x]; edge[tot].quan = quan;
    head[x] = tot;
    return;
}
void dfs(int p,int f)
{
    vis[p] = 1;gt[++cnt] = p;
    fa[p][0] = f; dep[p] = dep[f] + 1;
    for(int i = 1;i <= 20;i++)
        fa[p][i] = fa[fa[p][i-1]][i-1];
    for(int i = head[p];i;i = edge[i].next)
    {
        int e = edge[i].to;
        if(!vis[e]){fa[e][0] = p; dis[e] = dis[p] + edge[i].quan; dfs(e,p);}
    }
    return;
}
int LCA(int x,int y)
{
    if(dep[x] > dep[y]) swap(x,y);
    for(int i = 20;i >= 0;i--) if(dep[x] <= dep[y] - (1 << i)) y = fa[y][i];
    if(x == y) return x;
    for(int k = 20;k >= 0;k--)
        if(fa[x][k] != fa[y][k]) x = fa[x][k],y = fa[y][k];
    return fa[x][0];
}
void pushup(int now) {tmp[fa[gt[now]][0]] += tmp[gt[now]];}
bool check(int x)
{
    int ccc = 0,ans = 0;
    memset(tmp,0,sizeof(tmp));
    //把所有大于mid值的路径记录
    //并找出被所有这样路径覆盖的最长的道路
    for(int i = 1;i <= m;i++)
    {
        if(road[i].dis > x)
        {
            tmp[road[i].from] ++; tmp[road[i].to] ++;
            tmp[road[i].lca] -= 2;
            ans = max(ans,road[i].dis - x);
            ccc += 1;
        }
    }
    //Case #1:不存在大于二分答案值的线段
    if(!ccc) return false; 
    for(int i = n;i >= 1;i--) pushup(i);
    for(int i = 1;i <= n;i++) 
        //Case #2:存在满足题意的边，但是这条边被去掉后，用时还是会大于等于找到的ans
        if(tmp[i] == ccc /*满足题意的边*/ && dis[i] - dis[fa[i][0]] >= ans /*but长度大于mid*/) return false;
    return true; //满足所有筛选条件
}
signed main()
{
    n = rd;m = rd;
    for(int i = 1;i < n;i++)
    {
        int a,b,t;
        a = rd;b = rd;t = rd;
        add(a,b,t); add(b,a,t);
        all += t;
    }
    dfs(1,0);
    for(int i = 1;i <= m;i++)
    {
        road[i].from = rd; road[i].to = rd;
        road[i].lca = LCA(road[i].from,road[i].to);
        road[i].dis = dis[road[i].from] + dis[road[i].to] - 2 * dis[road[i].lca];
    }
    int l = 0,r = all;
    //二分
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid+1;
        else r = mid;
    }
    write(l);

    return 0;
}