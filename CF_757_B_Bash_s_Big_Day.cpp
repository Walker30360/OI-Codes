#include <bits/stdc++.h>
#define maxn 100010
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
//#define int long long
using namespace std;
inline int read(){long long s=0,w=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();} while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;}
inline void write(int x) {if(x < 0) putchar('-'),x=-x;static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);}
int n,s[maxn],ener,ans;
bool prime[maxn];
signed main()
{
    n = rd;
    for(int i = 1;i <= n;i++) ener = rd,s[ener]++;
    for(int i = 2;i <= maxn-10;i++)
    {
        if(prime[i]) continue;
        int now = s[i];
        for(int j = 2;j * i <= maxn-10;j++)
        {
            prime[j * i] = 1;now += s[j * i];
        }
        ans = max(ans,now);
    }
    write((ans == 0?1:ans));pc;

    return 0;
}