#include <bits/stdc++.h>
#define maxn 20
#define mod 1000000007
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
// #define int long long
typedef long long ll;
using namespace std;
struct mat
{
    ll n,m;
    ll v[maxn][maxn];
    mat() {memset(v,0,sizeof(v));}
    mat(ll N,ll M,ll one = 0)
    {
        n = N;m = M; memset(v,0,sizeof(v));
        if(one) for(int i = 1;i <= n;i++) v[i][i] = 1;
    }
};
mat operator*(const mat A,const mat B)
{
    mat C = mat(A.n,A.m);
    for(ll i = 1;i <= C.n;i++)
        for(ll j = 1;j <= C.m;j++)
            for(ll k = 1;k <= A.m;k++)
                C.v[i][j] = (C.v[i][j] + A.v[i][k] * B.v[k][j]) % mod;
    return C;
}
mat nw(mat A,ll mi)
{
    mat ret = mat(A.n,A.m,1);
    while (mi > 0) 
    {
        if (mi & 1) ret = ret * A;
        A = A * A;
        mi >>= 1;
    }
    return ret;
}
template <typename T>
inline T
read() {T sum = 0, fl = 1;int ch = getchar();for (; !isdigit(ch); ch = getchar())if (ch == '-') fl = -1;for (; isdigit(ch); ch = getchar()) sum = sum * 10 + ch - '0';return sum * fl;}

template <typename T>
inline void
write(T x) {if(x < 0) putchar('-'),x = -x;static T sta[35];T top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);return;}

ll n;
signed main()
{
    n = read<ll>();
    mat a = mat(1,2),b = mat(2,2);
    a.v[1][1] = 0; a.v[1][2] = 1;
    b.v[1][1] = 0; b.v[1][2] = b.v[2][1] = b.v[2][2] = 1;
    a = a * nw(b,n);
    write(a.v[1][1]);pc;

    return 0;
}