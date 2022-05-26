#include <bits/stdc++.h>
#define maxn 200010
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
//#define int long long
using namespace std;
int n,a[maxn];
signed main()
{
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    int ans = 0;
    sort(a+1,a+1+n);
    for(int i = 1;i <= n;i++)
        for(int j = i+1;j <= n;j++)
        {
            int p = a[i] * a[j];
            for(int k = j;k <= n;k++)
            {
                if(k != j && a[k] == p) {ans += 2;break;}
            }
        }
    cout << ans << endl;

    return 0;
}