#include <bits/stdc++.h>
#define maxn 110
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
#define mod 
//#define int long long
#define nosync
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
int a[maxn];
signed main()
{
    #ifdef nosync
    ios::sync_with_stdio(false);
    cin.tie(0);
    #endif
    int n,k;
    cin >> n >> k;
    int num = 0;
    for(int i = 1;i <= n;i++) {cin >> a[i];num = max(num,a[i]);}
    for(int i = 1;i <= k;i++)
    {
        int b;cin >> b;
        if(a[b] == num) cout << "Yes" << endl,exit(0);
    }
    cout << "No" << endl;

    return 0;
}