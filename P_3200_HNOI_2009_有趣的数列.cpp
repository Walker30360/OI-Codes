#include <bits/stdc++.h>
#define maxn 2000010
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
#define int long long
//#define nosync
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
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
    void write(double x){printf("%0.2lf",x);}
    void write(string s){for(char c:s)putchar(c);}
    template<typename type1,typename type2,typename ...typen>
    void write(type1 a1,type2 a2,typen ...an){
        write(a1);
        write(a2,an...);
    }
}using namespace IO;
int n,mod,ans = 1;
int prime[maxn],evprime[maxn],cnt[maxn];
int ksm(int A,int mi)
{
    int ret = 1;
    while(mi)
    {
        if(mi & 1) ret = ret * A % mod;
        A = A * A % mod;
        mi >>= 1;
    }
    return ret;
}
void init()
{
    int tot = 0;
    for(int i = 2;i <= 2*n;i++)
    {
        if(!evprime[i]) prime[++tot] = i,evprime[i] = i;
        for(int j = 1;j <= tot && i * prime[j] <= 2 * n;j++)
        {
            evprime[i * prime[j]] = prime[j];
            if(i % prime[j] == 0) break; //I end of prime
        }
    }
}
void euler()
{
    for(int i = 1;i <= n;i++)
        cnt[i] = -1;
    for(int i = n+2;i <= 2*n;i++)
        cnt[i] = 1;
}
signed main()
{
    #ifdef nosync
    ios::sync_with_stdio(false);
    cin.tie(0);
    #endif
    n = rd,mod = rd;
    init();
    euler();
    for(int i = 2*n;i > 1;i--)
        if(evprime[i] < i) //i is Not a prime
        {
            cnt[evprime[i]] += cnt[i];
            cnt[i/evprime[i]/*another prime*/] += cnt[i];
        }
    for(int i = 2;i <= 2 * n;i++)
        if(evprime[i] == i) //i is prime
            ans = ans * ksm(i,cnt[i]) % mod;
    write(ans);

    return 0;
}