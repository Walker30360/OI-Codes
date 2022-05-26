#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
int n,m;
int a[maxn],b[maxn],tot[maxn];
signed main()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= m;i++) cin >> b[i];
    for(int i = 1;i <= m;i++)
    {
        int step = 1;
        for(int j = 1;j <= n;j++)
        {
            if(a[j] == b[i] && tot[j] != 1) {tot[j] = 1,step = 0;break;}
        }
        if(step) {cout << "No" << endl;return 0;}
    }
    cout << "Yes" << endl;

    return 0;
}