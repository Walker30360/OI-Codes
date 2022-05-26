#include <bits/stdc++.h>
#define int long long
#define maxn 200010
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline int read(){int s=0,w=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();} while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;}
inline void write(int x) {static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);}
int n,k,a[maxn],r[maxn],ans;
void merge_sort(int s,int t){
	if(s == t) return ;
	int mid = (s+t)>>1;
	merge_sort(s,mid);
	merge_sort(mid+1,t);
	int i = s,j = mid+1,k = s;
	while(i <= mid && j <= t)
		if(a[i] > a[j]) r[k++] = a[i++];
		else r[k++] = a[j++],ans += mid-i+1;
	while(i <= mid) r[k++] = a[i++];
	while(j <= t) r[k++] = a[j++];
	for(int i = s;i <= t;i++) a[i] = r[i];
}
signed main()
{
	//ios::sync_with_stdio(false);
	//std::cin.tie(0);
	n = read(),k = read();
	for(int i = 1;i <= n;i++) a[i] = read() + a[i-1] - k;
	merge_sort(0,n);
	write(ans);

	return 0;
}