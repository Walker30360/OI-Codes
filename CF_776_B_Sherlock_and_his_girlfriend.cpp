#include <bits/stdc++.h>
#define maxn 100010
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
//#define int long long
using namespace std;
int n;int step[maxn] = {1,1};
inline int read(){long long s=0,w=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();} while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;}
inline void write(int x) {if(x < 0) putchar('-'),x=-x;static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);}
void aishishai()
{
    for(int i = 2;i * i <= n+1;i++)
    {
        if(step[i] == 0)
            for(int j = i*2;j <= n+1;j += i)
                step[j] = 1;
    }
}
signed main()
{
    n = rd;
    if(n < 3) write(1);else write(2);pc;
    aishishai();
    for(int i = 2;i <= n+1;i++)
        write(step[i]+1),ps;

    return 0;
}