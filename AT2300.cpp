#include <bits/stdc++.h>
#define int long long
#define maxn 300010
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline int read(){long long s=0,w=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();} while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;}
inline void write(int x) {static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);}
int n,m,tree[maxn];
struct nod
{
	int l,r; //分别表示输入的l和r
}a[maxn];
inline int len(nod x){return x.r - x.l + 1;}
inline int lowbit(int x){return x & -x;}
inline void add(int x,int y){while(x <= m+1){tree[x] += y;x += lowbit(x);}}
inline int query(int x){int ret = 0;while(x) {ret += tree[x];x -= lowbit(x);}return ret;}
inline int cmp(nod x,nod y){return len(x) < len(y);}
signed main()
{
	//ios::sync_with_stdio(false);
	//std::cin.tie(0);
	n = read();m = read();
	for(int i = 1;i <= n;i++) {a[i] = (nod){read(),read()};}
	sort(a+1,a+1+n,cmp); //按照覆盖长短从短到长排序
	int now = 1,tot = n;
	for(int d = 1;d <= m;d++)
	{
		while(len(a[now]) < d && now <= n){add(a[now].l,1);/*左端+1*/add(a[now].r+1,-1);/*右端-1*/;now++,tot--;} //即找到每个长度小于目前枚举到的d的区间
		int as = 0;
		for(int i = 0;i <= m;i += d)
			as += query(i);
		write(tot+as);putchar('\n');
	}


	return 0;
}