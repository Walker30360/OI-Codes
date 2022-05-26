#include <bits/stdc++.h>
#define maxn 
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
//#define int long long
using namespace std;
inline int read(){long long s=0,w=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();} while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;}
inline void write(int x) {if(x < 0) putchar('-'),x=-x;static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);}
int gcd(int x,int y)
{
    return y == 0 ? x : gcd(y,x % y);
}
void work()
{
    int a0 = rd,a1 = rd,b0 = rd,b1 = rd;
    int ans = 0;
    for(int x = 1;x * x <= b1;x++)
    {
        //枚举b1​的因子(也就是x)，如果这个数是a1​的整数倍并且满足gcd(x/a1,a0/a1)==1 && gcd(b1/b0,b1/x) == 1，则ans++
        if(b1 % x == 0)
        {
            if(x % a1 == 0 && gcd(x/a1,a0/a1)==1 && gcd(b1/b0,b1/x) == 1) ans++;
            if(x * x == b1) continue;
            int other = b1/x;
            if(other % a1 == 0 && gcd(other/a1,a0/a1)==1 && gcd(b1/b0,b1/other) == 1) ans++;
        }
    }
    write(ans);pc;
}
signed main()
{
    int n = rd;
    while(n--) work();

    return 0;
}