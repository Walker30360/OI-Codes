#include <bits/stdc++.h>
#define maxn 10000001
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
//#define int long long
using namespace std;
inline int read(){long long s=0,w=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();} while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;}
inline void write(int x) {if(x < 0) putchar('-'),x=-x;static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);}
int n,q;
int prime[maxn]; bool lst[maxn];
void init()
{
    int tot = 0;
    for(int i = 2;i <= n;i++)
    {
        if(!lst[i]) prime[++tot] = i;
        for(int j = 1;j <= tot && i * prime[j] <= n;j++)
        {
            lst[i * prime[j]] = 1;
            if(!i % prime[j]) break;
        }
    }
}
signed main()
{
    n = rd;
    init();
    int cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        if(prime[i] == 0) break;
        ++cnt;
        write(prime[i]);
        if(cnt % 5 == 0) pc;
        else ps;
    }

    return 0;
}