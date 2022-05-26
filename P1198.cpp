#include <bits/stdc++.h>
#define int long long
// #ifdef int
// #define INT_MIN LONG_LONG_MIN
// #define INT_MAX LONG_LONG_MAX
// #endif
#define maxn 200010
#define ls (now << 1) //=now*2
#define rs ((now << 1) | 1) //=now2+1
#define mid ((l + r)>>1)
using namespace std;
template <typename T>
inline T
read() {T sum = 0, fl = 1;int ch = getchar();for (; !isdigit(ch); ch = getchar())if (ch == '-') fl = -1;for (; isdigit(ch); ch = getchar()) sum = sum * 10 + ch - '0';return sum * fl;}

template <typename T>
inline void
write(T x) {if(x < 0) putchar('-'),x = -x;static T sta[35];T top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);return;}

int m,mod;
//Tree
int sum[maxn << 2],lazy[maxn << 2];

void pushup(int now,int l,int r) {sum[now] = max(sum[ls],sum[rs]);return;}
void build(int now,int l,int r)
{
    sum[now] = INT_MIN;
    if(l == r) return;
    build(ls,l,mid);
    build(rs,mid+1,r);
    return;
}
void ins(int now,int l,int r,int col,int v)
{
	if(l == r) {sum[now] = v;return;}
    if(col <= mid) ins(ls,l,mid,col,v);
    else ins(rs,mid+1,r,col,v);
    pushup(now,l,r);
}
int query(int now,int l,int r,int L,int R)
{
	int ret = INT_MIN;
	if(L <= l && r <= R) return sum[now];
	if(L <= mid) ret = max(ret,query(ls,l,mid,L,R));
    if(R > mid) ret = max(ret,query(rs,mid+1,r,L,R));
    return ret;
}
int pos = 0;
signed main()
{
    // cout << 1 << endl;
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    m = read<int>();mod = read<int>();
    int last = 0;
    for(int i = 1;i <= m;i++)
    {
        char c;
        cin >> c;
        if(c == 'A')
        {
            int t = read<int>();
            ins(1,1,m,++pos,(t+last) % mod);
        }
        else
        {
            int n = read<int>();
            if(n == 0) last = 0;
            else last = query(1,1,m,pos-n+1,m);
            write(last);putchar('\n');
        }
    }

    return 0;
}