#include <bits/stdc++.h>
#define maxn 110
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
#define mod 2009
//#define int long long
using namespace std;
int n,t;
struct mat
{
    int n,m;
    int v[maxn][maxn];
    mat(){memset(v,0,sizeof(v));}
    mat(int N,int M,bool one = 0)
    {
        n = N; m = M; memset(v,0,sizeof(v));
        if(one) for(int i = 1;i <= n;i++) v[i][i] = 1;
    }
};
mat operator*(mat A,mat B)
{
    mat C = mat(A.n,A.m);
    for(int i = 1;i <= C.n;i++)
        for(int j = 1;j <= C.m;j++)
            for(int k = 1;k <= A.m;k++)
                C.v[i][j] = (C.v[i][j] + A.v[i][k] * B.v[k][j]) % mod;
    return C;
}
mat nw(mat A,int mi)
{
    mat ret = mat(A.n,A.m,1);
    while(mi > 0)
    {
        if (mi & 1) ret = ret * A;
        A = A * A;
        mi >>= 1;
    }
    return ret;
}
inline int id(int x,int y) {return x + y * n;}
inline int read(){long long s=0,w=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();} while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;}
inline void write(int x) {if(x < 0) putchar('-'),x=-x;static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);}
signed main()
{
    n = rd; t = rd;
    int m = n * 9;
    mat mt = mat(m,m);
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= 8;j++) mt.v[id(i,j)][id(i,j-1)] = 1;
        for(int j = 1;j <= n;j++)
        {
            int x;
            scanf("%1d",&x);
            if(x != 0) mt.v[i][id(j,x-1)] = 1;
        }
    }
    mt = nw(mt,t);
    write(mt.v[1][n]);pc;

    return 0;
}