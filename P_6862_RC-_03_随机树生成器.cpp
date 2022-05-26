#include <bits/stdc++.h>
#define maxn 10000005
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
const int mod = 1e9+9;
#define int long long
#define nosync
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
int fac[maxn]; //阶乘
int inv[maxn]; //逆元
void work()
{
    int n,k;
    cin >> n >> k;
    int iv = (inv[n-1] - inv[k-1] + mod) % mod; //真正的逆元
    int ans = fac[n-1] * iv % mod;
    if(k != 1) ans += fac[n-1],ans %= mod;
    cout <<ans << endl;
}
inline void init()
{
    fac[0] = 1;
    for(int i = 1;i <= 1e7;i++) fac[i] = 1ll*fac[i-1] * i % mod;
    inv[1] = 1;
    for(int i = 2;i <= 1e7;i++) inv[i] = 1ll*(mod - mod / i) * inv[mod % i] % mod;
    for(int i = 1;i <= 1e7;i++) inv[i] = (inv[i-1] + inv[i]) % mod; //逆元前缀和
    return;
}  
int T;
signed main()
{
    #ifdef nosync
    ios::sync_with_stdio(false);
    cin.tie(0);
    #endif
    init();
    cin >> T;
    while(T--) work();

    return 0;
}