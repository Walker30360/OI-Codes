#include <bits/stdc++.h>
#define maxn 110
#define maxlen 1010
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
#define mod 
//#define int long long
#define nosync
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int n,m;
namespace bint{
    struct Bigint
    {
        string num;
        Bigint(){}
        Bigint(int x){stringstream p;p << x;p >> num;}
        Bigint(string x){num = x;}
        string operator~(){return num;}
        void operator=(int x){stringstream p;p << x;p >> num;}
        void operator=(string x){num = x;}
        char operator[](int x){return num[x];}
        int sz(){return num.size();}
        int to_int()
        {
            if(sz() > 9) return INT_MAX;
            stringstream p;p << num;int x;p >> x;
            return x;
        }
        long long to_ll()
        {
            if(sz() > 18) return LONG_LONG_MAX;
            stringstream p;p << num;long long x;p >> x;
            return x;
        }
    };
    Bigint operator+(Bigint A,Bigint B)
    {
        string ans;
        int l1 = A.sz(),l2 = B.sz();
        int mxl = max(l1,l2);
        int num1[maxn * 10] = {0},num2[maxn * 10] = {0};
        for(int i = 0;i < l1;i++) num1[l1-i-1] = A[i] - '0';
        for(int i = 0;i < l2;i++) num2[l2-i-1] = B[i] - '0';
        for(int i = 0;i < mxl;i++)
        {
            num1[i] += num2[i];
            num1[i+1] += num1[i]/10;
            num1[i] %= 10;
        }
        if(num1[mxl]) mxl++;
        for(int i = mxl-1;i >= 0;i--) ans += num1[i] + '0';
        return Bigint(ans);
    }
    Bigint operator*(Bigint A,int B)
    {
        string ans;
        int l = A.sz();
        int num[maxn * 10] = {0};
        for(int i = l-1;i >= 0;i--) num[l-i-1] = A[i] - '0';
        int add = 0;
        for(int i = 0;i < l;i++)
        {
            num[i] = num[i] * B + add;
            add = num[i] / 10;
            num[i] %= 10;
        }
        while(add) num[l++] = add % 10,add /= 10;
        for(int i = l-1;i >= 0;i--) ans += num[i] + '0';
        return Bigint(ans);
    }
}
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
    void write(bint::Bigint x){write(~x);}
    template<typename type1,typename type2,typename ...typen>
    void write(type1 a1,type2 a2,typen ...an){
        write(a1);
        write(a2,an...);
    }
}
using namespace IO;
using namespace bint;
Bigint dp[maxn][maxn];
void init()
{
    for(int i = 1;i <= 100;i++) dp[i][1] = 1;
    for(int i = 2;i <= 100;i++)
        for(int j = 1;j <= i;j++)
            dp[i][j] = dp[i-1][j-1] + (dp[i-1][j] * j);
    return;
}
void work()
{
    if(n < m) write(0,'\n');
    else write(dp[n][m].num,'\n');
}
signed main()
{
    #ifdef nosync
    ios::sync_with_stdio(false);
    cin.tie(0);
    #endif
    init();
    while(cin >> n >> m) work();

    return 0;
}