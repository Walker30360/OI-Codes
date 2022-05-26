//线段树

#include <bits/stdc++.h>
#define rd read()
#define maxn 1000100
using namespace std;
inline int read(){long long s=0,w=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();} while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;}
inline void write(int x) {if(x < 0) putchar('-'),x=-x;static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);}
int n,m;
int a[maxn << 5],level[maxn << 5];
struct segment_tree
{
    #define mid ((l+r) >> 1)
    int ls[maxn << 5],rs[maxn << 5],tree[maxn << 5],tot;
    void build(int &now,int l,int r)
    {
        now = ++tot;
        if(l == r) {tree[now] = a[l];return;}
        build(ls[now],l,mid); build(rs[now],mid+1,r);
        return;
    }
    void modify(int &now,int pre,int l,int r,int col,int v) //修改
    {
        now = ++tot; ls[now] = ls[pre]; rs[now] = rs[pre]; tree[now] = tree[pre]; //复制线段树
        if(l == r) {tree[now] = v;return;}
        if(col <= mid) modify(ls[now],ls[pre],l,mid,col,v);
        else modify(rs[now],rs[pre],mid+1,r,col,v);
        return;
    }
    int query(int now,int l,int r,int col)
    {
        if(l == r) return tree[now];
        if(col <= mid) return query(ls[now],l,mid,col);
        else return query(rs[now],mid+1,r,col);
    }
    #undef mid
}ST;
signed main()
{
    n = rd;m = rd;
    for(int i = 1;i <= n;i++) a[i] = rd;
    ST.build(level[0],1,n); //初始化建树（版本0）
    for(int i = 1;i <= m;i++)
    {
        int v,type,loc;
        v = rd,type = rd,loc = rd;
        if(type == 1)
        {
            int val = rd;
            ST.modify(level[i],level[v],1,n,loc,val);
        }
        else
        {
            write(ST.query(level[v],1,n,loc)); putchar('\n');
            level[i] = level[v]; //继承
        }
    }

    return 0;
}