/*
- 如果不考虑限制“偶数次”，第m个位置的情况就是C(m,(2^n)-1) -> 从可能的(2^n)-1个数里选出m个
- 加上此限制，就有 2 Cases
  > Case 1: 音阶在前m-1个集合中出现奇数次，则第m个集合中必有该音阶
  > Case 2: 音阶在前m-1个集合中出现偶数次，则第m个集合中必无该音阶
    根据Case 2推导，如果对于所有音阶都在前m-1个集合中出现偶数次，则该方案不合法
- 定义f[i]表示考虑到第i个集合时合法方案数
  > 不合法空集个数：f[i-1] -> 所有音阶都在前i-1个集合中出现偶数次
  > 重复出现同一音阶个数：f[i-2] * ((2^n)-1-(i-2)) -> 所有音阶都在前i-2个集合中出现偶数次的方案数 * 未选集合个数（总集合2^n个，已选i-2+1个）
- 各个方案都可能（或者说一定）存在i次重复，因此需要ans /= i
- f[i] = (C(i-1,ksm(2,n)-1) % mod - f[i-1] % mod - f[i-2] * (ksm(2,n) % mod - 1 - (i-2)) % mod) % mod / i; (i >= 3)
*/

#include <bits/stdc++.h>
#define maxn 1000010
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
#define mod 100000007
#define int ll
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
int ksm(ll A,int mi = mod-2)
{
    ll ret = 1;
    while(mi)
    {
        if(mi & 1) ret = ret * A % mod;
        A = A * A % mod;
        mi >>= 1;
    }
    return ret;
}
// ll res[maxn][67]={0};
// ll C(ll n,ll m){
//     if(m==0 || m==n) return 1;
//     if(res[n][m] != 0)return res[n][m];
//     return res[n][m] = C(n-1,m)+ C(n-1,m-1);//赋值给res[n][m]并返回
// }
int n,m;
ll f[maxn];
signed main()
{
    #ifdef nosync
    ios::sync_with_stdio(false);
    cin.tie(0);
    #endif
    n = rd,m = rd;
    int x = ksm(2,n) - 1;
    if(x < 0) x += mod;
    ll C = x * (x-1+mod) % mod * ksm(2) % mod; //递推计算组合数
    for(int i = 3;i <= m;i++)
    {
        f[i] = (C - f[i-1] - f[i-2] * ((x - (i-2) + mod) % mod) % mod + mod) % mod * ksm(i) % mod;
        C = C * (x - i + 1 + mod) % mod * ksm(i) % mod;
    }
    // write(x,'\n',C,'\n');
    // for(int i = 1;i <= m;i++)
    //     write(f[i],' ');
    write(f[m]);

    return 0;
}