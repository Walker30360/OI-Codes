#include <bits/stdc++.h>
#define maxn 200010
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
#define mod 
//#define int long long
//#define nosync
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
int t[maxn],n;
signed main()
{
    #ifdef nosync
    ios::sync_with_stdio(false);
    cin.tie(0);
    #endif
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int x;cin >> x;t[x]++;
    }
    

    return 0;
}