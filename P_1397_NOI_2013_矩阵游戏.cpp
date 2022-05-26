#include <bits/stdc++.h>
#define maxn 10
#define mod 1000000007
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
//#define int long long
typedef long long ll;
using namespace std;
struct mat
{
    ll n = 2;
    ll v[maxn][maxn];
    mat() {memset(v,0,sizeof(v));}
    mat(bool one)
    {
        memset(v,0,sizeof(v));
        if(one) for(int i = 1;i <= n;i++) v[i][i] = 1;
    }
};
mat line; mat down;
mat ans,base;
mat operator*(const mat A,const mat B)
{
    mat C = mat();
    for(int i = 1;i <= C.n;i++)
        for(int j = 1;j <= C.n;j++)
            for(int k = 1;k <= C.n;k++)
                C.v[i][j] = (C.v[i][j] + A.v[i][k] * B.v[k][j]) % mod;
    return C;
}
mat nw(mat A,ll mi)
{
    mat ret = mat(1);
    while (mi > 0) 
    {
        if (mi & 1) ret = ret * A;
        A = A * A;
        mi >>= 1;
    }
    return ret;
}
inline int read(){long long s=0,w=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();} while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;}
inline void write(int x) {if(x < 0) putchar('-'),x=-x;static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);}
string strn,strm;
ll n,m,a,b,c,d;
inline void inital()
{
    line.v[1][1] = a; line.v[1][2] = 0; line.v[2][1] = b; line.v[2][2] = 1;
    down.v[1][1] = c; down.v[1][2] = 0; down.v[2][1] = d; down.v[2][2] = 1;
    return;
}
inline void cacu()
{
    ans.v[1][1] = ans.v[1][2] = 1;
    base = nw(line,m-1);

    base = base * down;
    base = nw(base,n-1);

    base = base * nw(line,m-1);
    ans = ans * base;
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> strn >> strm;
    cin >> a >> b >> c >> d;
    inital();
    int lenn = strn.size(),lenm = strm.size();
    for(int i = 0;i < lenn;i++)
    {
        n = (n << 1) + (n << 3) + (strn[i] ^ '0'); //The same as n = 10 * n + (strn[i] - '0');
        if(a == 1) n %= mod;
        else n %= (mod - 1);
    }
    for(int i = 0;i < lenm;i++)
    {
        m = (m << 1) + (m << 3) + (strm[i] ^ '0');
        if(a == 1) m %= mod;
        else m %= (mod - 1);
    }
    cacu();
    write(ans.v[1][1]);pc;

    return 0;
}