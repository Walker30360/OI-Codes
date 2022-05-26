#include <bits/stdc++.h>
#define maxn 1000010
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
//#define int long long
using namespace std;
inline int read(){long long s=0,w=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();} while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;}
inline void write(int x) {if(x < 0) putchar('-'),x=-x;static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);}
int n,m,a[maxn],t[maxn],lcmp[maxn],ans,lcmmax = 1;
bool vis[maxn];
signed main()
{
    n = rd;m = rd;
    int tot = 0;
    // for(int i = 1;i <= n;i++) {int x = rd; if(x <= m) a[++tot] = x;}
    for(int i = 1;i <= n;i++)
    {
        a[i] = rd; if(a[i] <= m) t[a[i]]++;
    }
    for(int i = 1;i <= n;i++)
    {
        if(a[i] > m || vis[a[i]]) continue;
        for(int j = 1;j * a[i] <= m;j++)
            lcmp[a[i] * j] += t[a[i]];
        vis[a[i]] = 1;
    }
    for(int i = 1;i <= m;i++)
    {
        if(ans < lcmp[i])
            ans = lcmp[i],lcmmax = i;
    }
    write(lcmmax);ps;write(ans);pc;
    for(int i = 1;i <= n;i++)
    {
        if(lcmmax % a[i] == 0)
            write(i),ps;
    }

    return 0;
}