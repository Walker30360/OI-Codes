#include <bits/stdc++.h>
#define maxn 110
#define mod 2017
#define rd read<ll>()
#define pc putchar('\n')
#define ps putchar(' ')
//#define int long long
typedef long long ll;
using namespace std;
template <typename T>
inline T
read() {T sum = 0, fl = 1;int ch = getchar();for (; !isdigit(ch); ch = getchar())if (ch == '-') fl = -1;for (; isdigit(ch); ch = getchar()) sum = sum * 10 + ch - '0';return sum * fl;}

template <typename T>
inline void
write(T x) {if(x < 0) putchar('-'),x = -x;static T sta[35];T top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);return;}

struct mat
{
    int n;
    ll v[maxn][maxn];
    mat(){memset(v,0,sizeof(v));}
    mat(int N,bool one = 0)
    {
        n = N;; memset(v,0,sizeof(v));
        if(one) for(int i = 1;i <= n;i++) v[i][i] = 1;
    }
};
mat operator*(mat A,mat B)
{
    mat C = mat(A.n);
    for(int i = 1;i <= C.n;i++)
        for(int j = 1;j <= C.n;j++)
            for(int k = 1;k <= C.n;k++)
                C.v[i][j] = (C.v[i][j] + A.v[i][k] * B.v[k][j] % mod) % mod;
    return C;
}
mat nw(mat A,ll mi)
{
    mat ret = mat(A.n,1);
    while(mi > 0)
    {
        if(mi & 1) ret = ret * A;
        A = A * A;
        mi >>= 1;
    }
    return ret;
}
ll n,m;
signed main()
{
    n = rd;m = rd;n++;
    #undef rd
    #define rd read<int>()
    mat a = mat(n,1);
    for(int i = 1;i <= m;i++)
    {
        int x = rd,y = rd;
        a.v[x][y] = a.v[y][x] = 1;
    }
    for(int i = 1;i <= n;i++)
        a.v[i][n] = 1;
    mat anss;
    int t = rd;
    anss = nw(a,t);
    ll ans = 0;
    for(int i = 1;i <= n;i++) ans = (ans + anss.v[1][i]) % mod;
    write(ans);

    return 0;
}