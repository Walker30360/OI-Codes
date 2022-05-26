#include <bits/stdc++.h>
#define mod 1000000007
#define maxn 13
#define rd read()
#define int long long
using namespace std;
struct mat
{
    int n,v[maxn][maxn];
    mat() {memset(v,0,sizeof(v));}
    mat(int N,bool one = 0)
    {
        n = N;
        memset(v,0,sizeof(v));
        if(one) for(int i = 1;i <= n;i++) v[i][i] = 1;
    }
};
mat operator * (mat A,mat B)
{
    mat C = mat(A.n);
    for(int i = 1;i <= C.n;i++)
        for(int j = 1;j <= C.n;j++)
            for(int k = 1;k <= A.n;k++)
                C.v[i][j] = (C.v[i][j] + A.v[i][j] * B.v[j][k]) % mod;
    return C; 
}
mat nw (mat A,int mi)
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
int pow(int x,int mi)
{
    if(mi == 0) return 1;
    int ret = 1;
    while(mi--)
    {
        ret *= x;
        ret %= mod;
    }
    return ret;
}
int n,k;
mat C;
void initC()
{
    C.v[0][0] = 1;
    for(int i = 1;i <= k;i++)
    {
        C.v[i][0] = 1;
        for(int j = 1;j <= i;j++)
            C.v[i][j] = C.v[i-1][j-1] + C.v[i-1][j];
    }
    return;
}
inline int read(){long long s=0,w=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();} while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;}
inline void write(int x) {if(x < 0) putchar('-'),x=-x;static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);}
mat A,e,P;
signed main()
{
    n = rd,k = rd;
    A.n = k; C.n = k;
    if(n == 1) write(1),exit(0);
    if(n == 2) write(1+(int)pow(2,k)),exit(0);
    initC();
    A.v[1][1] = 2;
    for(int i = 2;i <= k + 2;i++)
    {
        A.v[1][i] = C.v[k][i-2];
        for(int j = i;j <= k + 2;j++)
            A.v[i][j] = C.v[k-i+2][j-i];
    }
    A = nw(A,n-2);
    mat base = mat(k);
    for(int i = 1;i <= k+2;i++) base.v[i][1] = 1;
    A = A * base;
    write((A.v[1][1] + pow(n%mod,k) % mod) % mod);putchar('\n');

    return 0;
}