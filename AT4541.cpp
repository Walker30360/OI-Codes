#include <bits/stdc++.h>
#define nosync
#define maxn 3010
#define mod 1000000007
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
//#define int long long
using namespace std;
namespace IO{
    inline int read(){
        int x=0;int f=1;char ch;
        while((ch=getchar())<'0'||x>'9')if(ch=='-')f=-1;
        while(ch>='0'&&ch<='9'){x=((x<<1)+(x<<3)+(ch^48)),ch=getchar();}
        return x*f;
    }
    inline string read(){
        #ifdef nosync
        ios::sync_with_stdio(false);
        cin.tie(0);
        #endif
        string s;cin >> s;
        return s;
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
int dp[maxn][maxn]; //dp[i][j] -> 在第i个位置，前面的数为序列当中第j大的可能数
int n,s;
signed main()
{
    n = rd,s = rd;
    dp[1][1] = 1;
    for(int i = 2;i <= n;i++)
    {
        if(s[i-2] == '<')
            for(int j = 1;j <= i;j++)
                dp[i][j] = (dp[i][j-1]+dp[i-1][j-1]) % mod;
        else
            for(int j = i-1;j >= 1;j--)
                dp[i][j] = (dp[i][j+1] + dp[i-1][j]) % mod;
    }

    return 0;
}