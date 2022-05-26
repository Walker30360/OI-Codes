#include <bits/stdc++.h>
#define rd read()
#define maxn 200010
using namespace std;
inline int read(){long long s=0,w=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();} while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;}
inline void write(int x) {if(x < 0) putchar('-'),x=-x;static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);}
int n,m;
int a[maxn << 5],tmp[maxn << 5],level[maxn << 5];
struct segment_tree
{
    #define mid ((l+r) >> 1)
    int sum[maxn << 5],ls[maxn << 5],rs[maxn << 5],tot;
    void build(int &now,int l,int r)
    {
        now = ++tot;
        sum[now] = 0;
        if(l < r) build(ls[now],l,mid),build(rs[now],mid+1,r);
        return;
    }
    void modify(int &now,int pre,int l,int r,int v)
    {
        now = ++tot;
        ls[now] = ls[pre]; rs[now] = rs[pre]; sum[now] = sum[pre] + 1;
        if(l < r) v <= mid?modify(ls[now],ls[pre],l,mid,v):modify(rs[now],rs[pre],mid+1,r,v);
        return;
    }
    int query(int L,int R,int l,int r,int col)
    {
        if(l >= r) return l;
        int x = sum[ls[R]] - sum[ls[L]];
        return x >= col?query(ls[L],ls[R],l,mid,col):query(rs[L],rs[R],mid+1,r,col - x);
    }
    #undef mid
}ST;
signed main()
{
    n = rd;m = rd;
    for(int i = 1;i <= n;i++) tmp[i] = a[i] = rd;
    sort(tmp+1,tmp+1+n);
    int len = unique(tmp+1,tmp+1+n)-tmp-1;
    ST.build(level[0],1,m);
    for(int i = 1;i <= n;i++)
    {
        //离散化
        int v = lower_bound(tmp+1,tmp+1+m,a[i])-tmp;
        ST.modify(level[i],level[i-1],1,m,v);
    }
    for(int i = 1;i <= m;i++)
    {
        int l = rd,r = rd,k = rd;
        int loc = ST.query(level[l-1],level[r],1,m,k);
        write(tmp[loc]); putchar('\n');
    }

    return 0;
}