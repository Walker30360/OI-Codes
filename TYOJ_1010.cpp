#include <bits/stdc++.h>
#define maxn 1000010
#define rd read()
using namespace std;
inline int read(){long long s=0,w=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();} while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;}
inline void write(int x) {if(x < 0) putchar('-'),x=-x;static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);}
int n,q;
basic_string<pair<int,int>> edge[maxn];
int f[maxn],fa[maxn][30],dep[maxn],dis[maxn],ipf[maxn],d[maxn];
signed main()
{
    n = rd;q = rd;
    for(int i = 1;i < n;i++) ipf[i] = rd;
    for(int i = 1;i < n-2;i++) f[i] = i;

}