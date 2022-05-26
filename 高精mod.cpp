#include <bits/stdc++.h>
#define maxn 
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
//#define int long long
using namespace std;

signed main()
{
    string s; 
    int mod;
    cin >> s >> mod;
    int ans = 0;
    for(char c:s)
    {
        ans = 10 * ans + (c ^ '0');
        ans %= m;
    }
    cout << ans << endl;

    return 0;
}