#include <bits/stdc++.h>
#include <atcoder/math>
#define maxn 200010
using namespace std;
#define rd read()
inline int read(){long long s=0,w=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();} while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;}
inline void write(int x) {if(x < 0) putchar('-'),x=-x;static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);}
struct nod
{
    int x,y,hight,l;
}star[maxn << 4];
#define mid ((l+r) >> 1)
int ls[maxn << 4],rs[maxn << 4],mx[maxn << 4],lazy[maxn << 4],tot;
void pushdown(int now)
{
    if(!ls[now]) ls[now] = ++tot;
    if(!rs[now]) rs[now] = ++tot;
    mx[ls[now]] += lazy[now]; mx[rs[now]] += lazy[now];
    lazy[ls[now]] += lazy[now]; lazy[rs[now]] += lazy[now];
    lazy[now] = 0;
    return;
}
void pushup(int now)
{
    mx[now] = max(mx[ls[now]],mx[rs[now]]);
}
void modify(int &now,int l,int r,int L,int R,int v)
{
    if(!now) now = ++tot;
    if(L <= l && r <= R){lazy[now] += v;mx[now] += v;return;}
    pushdown(now);
    if(L <= mid) modify(ls[now],l,mid,L,R,v);
    if(mid + 1 <= R) modify(rs[now],mid+1,r,L,R,v);
    pushup(now);
}
#undef mid
bool cmp(nod x,nod y)
{
    return (x.x==y.x?x.l>y.l:x.x<y.x); //扫描线
}
int T,root;
signed main()
{
    T = read();
    while(T--)  
    {
        int n = rd,w = rd,h = rd;
        //题意转化：平面上有N个矩形，求在哪个坐标可以使权值总和最大
        if(w == 1 || h == 1)
        {
            write(0);putchar('\n');
            continue;
        }
        //离散化
        int tot = 0;
        for(int i = 1;i <= n;i++)
        {
            int x = rd,y = rd,l = rd;
            star[++tot] = (nod){x,y,y+h-1,l}; //高度为x+h-1
            star[++tot] = (nod){x+w-1,y,y+h-1,-l};
        }
        sort(star+1,star+1+tot,cmp);
        int ans = 0;
        for(int i = 1;i <= tot;i++)
        {
            modify(root,0,1e9,star[i].y,star[i].hight,star[i].l);
            ans = max(ans,mx[root]);
        }
        write(ans);putchar('\n');
    }

    return 0;
}