#include <bits/stdc++.h>
#define maxn 
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
#define int long long
using namespace std;
int work(int n)
{
    int ans = n;
    for(int i = 2;i * i <= n;i++)
    {
        if(n % i == 0)
        {
            int ti = 0;
            while(n % i == 0) ti++,n /= i;
            ans /= i,ans *= ti * i - ti + i;
        }
        if(n > 1) ans /= n,ans *= n + n - 1;
    }
    return ans;
}
signed main()
{
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cout << work(n);

    return 0;
}