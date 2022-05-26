#include <bits/stdc++.h>
#define maxn 50010 << 2
#define rd read()
using namespace std;
int n,k;
int ans;
int fa[maxn][30],dep[maxn];
int lg[maxn]; 
int power[maxn];
basic_string<int> tr[maxn];
inline int read(){long long s=0,w=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();} while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;}
inline void write(int x) {if(x < 0) putchar('-'),x=-x;static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);}
void dfs(int p,int f)
{
    fa[p][0] = f; dep[p] = dep[f] + 1;
    for(int i = 0;fa[p][i];i++)
        fa[p][i+1] = fa[fa[p][i]][i];
    for(int i : tr[p])
    {
        if(i != f) dfs(i,p);
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
void query(int now,int fa)
{
	for(int i : tr[now])
	{
		if(i == fa) continue;
		query(i,now);
		power[now] += power[i];
	}
	ans = max(ans,power[now]);
    return;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("P3128_2.in","r",stdin);
    #endif
	n = rd;k = rd;
	for(int i = 1;i < n;i++)
    {
    	int x,y;
        x = rd;y = rd;
        tr[x] += y;tr[y] += x;
    }
    dfs(1,0); //init
    for(int i = 1;i <= k;i++)
    {
    	int start,end;
    	start = rd; end = rd;
    	int lca = LCA(start,end);
    	power[start]++; power[end]++;
    	power[lca]--; power[fa[lca][0]]--;
	}
	query(1,0);
	write(ans);
	
	return 0;
}