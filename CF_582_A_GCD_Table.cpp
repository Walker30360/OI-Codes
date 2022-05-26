#include <bits/stdc++.h>
#define maxn 510
#define maxm 250010
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
//#define int long long
using namespace std;
int n;
int ans[maxn],tot;
int gcd(int x,int y)
{
    return y == 0?x:gcd(y,x % y);
}
inline int read(){long long s=0,w=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();} while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;}
inline void write(int x) {if(x < 0) putchar('-'),x=-x;static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);}
int num[maxm],cnt;
map<int,int> nb;
signed main()
{
    n = rd;
    for(int i = 1;i <= n*n;i++)
    {
        int x = rd;
        if(!nb[x]) num[++cnt] = x;
        nb[x]++;
    }
    sort(num+1,num+1+cnt);
    for(int i = cnt;i >= 1 && tot < n;)
    {
        while(!nb[num[i]]) i--;
        ans[++tot] = num[i]; nb[num[i]]--;
        for(int j = 1;j < tot;j++) nb[gcd(num[i],ans[j])] -= 2; //将两个全部删除，可以视为x,k都不会对数表中的值造成影响
    }
    for(int i = 1;i <= tot;i++) write(ans[i]),ps;

    return 0;
}