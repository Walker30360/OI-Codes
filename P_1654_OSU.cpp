#include <bits/stdc++.h>
#define maxn 100010
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
#define mod 
//#define int long long
// #define nosync
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
    void write(double x){printf("%0.1lf",x);}
    void write(string s){for(char c:s)putchar(c);}
    template<typename type1,typename type2,typename ...typen>
    void write(type1 a1,type2 a2,typen ...an){
        write(a1);
        write(a2,an...);
    }
}using namespace IO;
int n;
double p[maxn];
double E1[maxn]; //E[i]
double E2[maxn]; //E[i^2]
double ans;
signed main()
{
    #ifdef nosync
    ios::sync_with_stdio(false);
    cin.tie(0);
    #endif
    n = rd;
    for(int i = 1;i <= n;i++) cin >> p[i];
    for(int i = 1;i <= n;i++)
    {
        E1[i] = (E1[i-1]+1.0) * p[i];
        E2[i] = p[i] * (E2[i-1] + 2.0 * E1[i-1] + 1.0);
        ans += p[i] * (3.0 * E2[i-1] + 3.0 * E1[i-1] + 1.0);
    }
    write(ans);

    return 0;
}