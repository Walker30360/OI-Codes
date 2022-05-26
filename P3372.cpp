// Problem: P3372 【模板】线段树 1
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3372
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define int long long
#define maxn 100005
#define ls (now << 1) //=now/2
#define rs ((now << 1) | 1) //=now/2+1
#define mid ((l + r)>>1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int sum[maxn << 2],lazy[maxn << 2]; //maxn << 2 = maxn * 4
int n,m;
inline int read(){long long s=0,w=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();} while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;}
inline void write(int x) {static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);}
void pushup(int now,int l,int r) {sum[now] = sum[ls] + sum[rs];return;}
void pushdown(int now,int l,int r)
{
	sum[ls] += (mid-l+1) * lazy[now];
	sum[rs] += (r-mid) * lazy[now];
	lazy[ls] += lazy[now];lazy[rs] += lazy[now];lazy[now] = 0;
	return;
}
void build(int now,int l,int r)
{
	if(l == r) {sum[now] = read();return;} //叶子节点
	build(ls,l,mid); build(rs,mid+1,r); pushup(now,l,r);
	return;
}
void ins(int now,int l,int r,int L,int R,int v) //向区间L~R中的每个数+v
{
	if(L <= l && r <= R) {sum[now] += (r-l+1)*v;lazy[now] += v;return;}
	if(lazy[now]) pushdown(now,l,r); //将lazy下推
	if(L <= mid) ins(ls,l,mid,L,R,v);
	if(mid + 1 <= R) ins(rs,mid+1,r,L,R,v);
	pushup(now,l,r);
	return;
}
int query(int now,int l,int r,int L,int R)
{
	int ret = 0;
	if(L <= l && r <= R) return sum[now];
	pushdown(now,l,r);
	if(L <= mid) ret+=query(ls,l,mid,L,R);
	if(mid+1 <= R) ret+=query(rs,mid+1,r,L,R);
	return ret;
}
signed main()
{
	//ios::sync_with_stdio(false);
	//std::cin.tie(0);
	n = read(),m = read();
	build(1,1,n);
	for(int i = 1;i <= m;i++)
	{
		int type;type = read();
		int x,y;x = read(),y = read();
		if(type == 1)
		{
			int k;k = read();
			ins(1,1,n,x,y,k);
		}
		else
		{
			cout << query(1,1,n,x,y) << endl;
		}
	}

	return 0;
}