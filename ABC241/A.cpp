#include <bits/stdc++.h>
#define maxn 
using namespace std;
int a[10];
signed main()
{
    int ans = 0;
    for(int i = 0;i <= 9;i++) cin >> a[i];
    for(int i = 1;i <= 3;i++)
    {
        ans = a[ans];
        // cout << ans << endl;
    }
    cout << ans << endl;

    return 0;
}