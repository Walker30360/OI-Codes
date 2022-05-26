#include <bits/stdc++.h>
#define int long long
#define maxn 110
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
#define mod 
//#define int long long
#define nosync
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
int n,m;
int dis[maxn][maxn];
int edge[maxn][maxn];
inline void add(int u,int v,int w) //防重边处理
{
    dis[u][v] = min(dis[u][v],w);
    dis[v][u] = min(dis[v][u],w);
    edge[u][v] = min(edge[u][v],w);
    edge[v][u] = min(edge[v][u],w);
}
signed main()
{
    #ifdef nosync
    ios::sync_with_stdio(false);
    cin.tie(0);
    #endif
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            if(i != j) dis[i][j] = edge[i][j] = INT_MAX;
    for(int i = 1;i <= m;i++)
    {
        int u,v,w;cin >> u >> v >> w;
        add(u,v,w);
    }
    int ans = INT_MAX;
    for(int k = 1;k <= n;k++)
    {
        for(int i = 1;i < k;i++)
            for(int j = i+1;j < k;j++)
                ans = min(ans,dis[i][j] + edge[i][k] + edge[k][j]);
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                dis[i][j] = dis[j][i] = min(dis[i][j],dis[i][k] + dis[k][j]);
    }
    if(ans == INT_MAX) cout << "No solution." << endl;
    else cout << ans << endl;

    return 0;
}
