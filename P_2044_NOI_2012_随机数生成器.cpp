#include <bits/stdc++.h>
#define maxn 10
// #define mod 1000000007
#define rd read<int>()
#define pc putchar('\n')
#define ps putchar(' ')
#define int long long
typedef long long ll;
using namespace std;
int mod;
template <typename T>
inline T
read() {T sum = 0, fl = 1;int ch = getchar();for (; !isdigit(ch); ch = getchar())if (ch == '-') fl = -1;for (; isdigit(ch); ch = getchar()) sum = sum * 10 + ch - '0';return sum * fl;}

template <typename T>
inline void
write(T x) {if(x < 0) putchar('-'),x = -x;static T sta[35];T top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);return;}

//快速（龟速？）乘法
int Quickmix(int A,int B)
{
    int ret = 0;
    while(B > 0)
    {
        if(B & 1) ret = (ret + A) % mod;
        A = (A << 1) % mod;
        B >>= 1;
    }
    return ret;
}
struct mat
{
    int n = 2;
    int v[maxn][maxn];
    mat(){memset(v,0,sizeof(v));}
    mat(int N,bool one = 0)
    {
        n = N; memset(v,0,sizeof(v));
        if(one) for(int i = 1;i <= n;i++) v[i][i] = 1;
    }
};
mat A = mat(2),base = mat(2);
mat operator*(mat X,mat B)
{
    mat C = mat(X.n);
    for(int i = 1;i <= C.n;i++)
        for(int j = 1;j <= C.n;j++)
            for(int k = 1;k <= C.n;k++)
                C.v[i][j] = (C.v[i][j] + Quickmix((X.v[i][k] % mod),(B.v[k][j] % mod)) % mod) % mod;
    return C;
}
mat nw(mat X,ll mi)
{
    while(mi > 0)
    {
        if(mi & 1) X = X * base;
        base = base * base;
        mi >>= 1;
    }
    return X;
}

int a,c,x0,n,g;
void init()
{
    A.v[1][1] = x0; A.v[1][2] = c;
    base.v[1][1] = a; base.v[2][1] = base.v[2][2] = 1;
    return;
}
signed main()
{
    mod = rd;a = rd;c = rd;x0 = rd;n = rd;g = rd;
    init();
    A = nw(A,n);
    write(A.v[1][1] % g);pc;

    return 0;
}