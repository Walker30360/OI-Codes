#include <bits/stdc++.h>
#define maxn 1010
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
#define mod 
//#define int long long
//#define nosync
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
int c[5],n;
namespace IO{
    inline int read(){
        int x=0;int f=1;char ch;
        while((ch=getchar())<'0'||x>'9')if(ch=='-')f=-1;
        while(ch>='0'&&ch<='9'){x=((x<<1)+(x<<3)+(ch^48)),ch=getchar();}
        return x*f;
    }
    void write(char x){putchar(x);}
    void write(const char *x){for(;*x;++x)putchar(*x);}
    void write(char *x){for(;*x;++x)putchar(*x);}
    void write(signed x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar('0'+x-x/10*10);}
    void write(long long x){
        if(x<0)putchar('-'),x=-x;
        if(x>9)write(x/10);
        putchar('0'+x-x/10*10);
    }
    #ifdef bint
    void write(Bigint x){write(~x);}
    #endif
    void write(double x){printf("%0.2lf",x);}
    void write(string s){for(char c:s)putchar(c);}
    template<typename type1,typename type2,typename ...typen>
    void write(type1 a1,type2 a2,typen ...an){
        write(a1);
        write(a2,an...);
    }
}using namespace IO;
int dp[maxn];
void work()
{
    int d[5],s;
    for(int i = 1;i <= n;i++) d[i] = rd;
    s = rd;

}
inline void init() //预处理不考虑个数限制的情况，即 集合M
{
    for(int i = 1;i <= 4;i++)
        for(int j = 1;j <= maxn;j++)
        {
            dp[j] += dp[j - c[i]];
        }
    return;
}
signed main()
{
    #ifdef nosync
    ios::sync_with_stdio(false);
    cin.tie(0);
    #endif
    for(int i = 1;i <= 4;i++) c[i] = rd;
    n = rd;
    init();
    while(n--) work();

    return 0;
}