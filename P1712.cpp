#include <bits/stdc++.h>
#define mid ((tree[now].l + tree[now].r) >> 1)
#define ls (now << 1)
#define rs ((now << 1)|1)
#define maxn 5000010
using namespace std;
inline int read(){long long s=0,w=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();} while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;}
inline void write(int x) {if(x < 0) putchar('-'),x=-x;static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);}
int n,m,tmp[maxn << 2],tot,maxlen;
struct nod
{
    int l,r,len;
}a[maxn << 2];

struct treedata
{
    int l,r,lazy,sum;
}tree[maxn << 2];

void pushup(int now) {tree[now].sum = max(tree[ls].sum,tree[rs].sum);}

void build(int now,int l,int r)
{
    tree[now].l = l;tree[now].r = r;
    if(l == r)	return;
    build(ls,l,mid);
    build(rs,mid + 1,r);
    return;
}

void pushdown(int now)
{
    tree[ls].lazy += tree[now].lazy;
    tree[rs].lazy += tree[now].lazy;
	tree[ls].sum += tree[now].lazy;
	tree[rs].sum += tree[now].lazy;
	tree[now].lazy = 0;
    return;
}

void ins(int now,int l,int r,int v)
{
    if(l <= tree[now].l && tree[now].r <= r){tree[now].lazy += v;tree[now].sum += v;return;}
	pushdown(now);
	if(l <= mid) ins(ls,l,r,v);
	if(r > mid)  ins(rs,l,r,v);
	pushup(now);
    return;
}
bool cmp(nod x,nod y) {return x.len < y.len;}
signed main()
{
    n = read();m = read();
    for(int i = 1;i <= n;i++) 
        a[i].l = read(),a[i].r = read(),a[i].len = a[i].r-a[i].l,tmp[++tot] = a[i].l,tmp[++tot] = a[i].r,tmp[++tot] = a[i].r+1;
    sort(a+1,a+1+n,cmp);
    sort(tmp+1,tmp+1+tot);
    tot = unique(tmp+1,tmp+1+tot) - tmp - 1;
    int mil = INT_MAX,mxr = INT_MIN;
    for(int i = 1;i <= n;i++)
    {
        a[i].l = lower_bound(tmp+1,tmp+1+tot,a[i].l) - tmp; mil = min(mil,a[i].l);
        a[i].r = lower_bound(tmp+1,tmp+1+tot,a[i].r) - tmp; mxr = max(mxr,a[i].r);
    }
    build(1,mil,mxr);
    int l = 1,ans = INT_MAX;
    for(int i = 1;i <= n;i++)
    {
        ins(1,a[i].l,a[i].r,1);
        while(tree[1].sum >= m) //根节点
        {
            ans = min(ans,a[i].len - a[l].len);
            //更新线段树
            ins(1,a[l].l,a[l].r,-1); l++;
        }
    }
    if(ans == INT_MAX) cout << -1;
    else cout << ans;

    return 0;
}