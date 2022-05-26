#include<bits/stdc++.h>
#define int long long
#define rd read()
#define maxn 300010 << 2
using namespace std;
int n,m;
const int mod = 998244353;
bool book[maxn];
basic_string<int> tr[maxn];
inline int read(){long long s=0,w=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();} while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;}
inline void write(int x) {if(x < 0) putchar('-'),x=-x;static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);}
int fa[maxn][50],dep[maxn];
bool vis[maxn];
int val[maxn][60]; //val[i][j] 从点i到根节点1的每一个点深度j次方之和
int mix[60] = {1}; //mix[i] 点深度的i次方，因为每次dfs不同的点这个数组都会被刷新，因此不需要二维
// void dfs(int p,int f)
// {
//     fa[p][0] = f; dep[p] = dep[f] + 1;
//     for(int i = 1;fa[p][i];i++) fa[p][i] = fa[fa[p][i-1]][i-1];
//     for(int i : tr[p])
//     {
//         if(i == f) continue;
//         for(int j = 1;j <= 50;j++) mix[j] = mix[j-1] * dep[i] % mod;
//         for(int j = 1;j <= 50;j++) val[i][j] = (mix[j] + val[p][j]) % mod;
//         dfs(i,p);
//     }
//     return;
// }

void dfs(int p)
{
    book[p] = 1;
    for(int i = 0;fa[p][i];i++) fa[p][i+1] = fa[fa[p][i]][i];
    for(int i : tr[p])
    {
        if(book[i]) continue; //找过了就是父亲结点
        fa[i][0] = p; dep[i] = dep[p] + 1;
        for(int j = 1;j <= 50;j++) mix[j] = mix[j-1] * dep[i] % mod;
        for(int j = 1;j <= 50;j++) val[i][j] = (mix[j] + val[p][j]) % mod; //Reason:点i到根节点的路径之和为val[i][j]，则应该是mix[j] （i点深度的j次方）+ val[p][j]（现在dfs的点——也就是i的father——到根节点1的数据之和）
        dfs(i);
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
signed main()
{
    n = rd;
    for(int i = 1;i < n;i++)
    {
        int x = rd,y = rd;
        tr[x] += y;tr[y] += x;
    }
    dfs(1);
    m = rd;
    while(m--)
    {
        int i = rd,j = rd,k = rd;
        int lca = LCA(i,j);
        int ans = (val[i][k] + val[j][k] - val[fa[lca][0]][k] - val[lca][k] + 2 * mod) % mod; //加上2 * mod防止出现负数
        write(ans);putchar('\n');
    }

    return 0;
}