#include <bits/stdc++.h>

using namespace std;
int n,pp;
void dfs(int dep,int v)
{
    if(v == 0 || v == 10) return;
    if(dep == n) 
    {
        // cout << v << endl;
        pp++; pp %= 998244353;
        return;
    }
    for(int i = -1;i <= 1;i++)
    {
        dfs(dep+1,v+i);
    }
    return;
}
signed main()
{
    pp = 0;
    cin >> n;
    for(int i = 1;i <= 9;i++)
    {
        dfs(1,i);
    }
    cout << pp % 998244353 << endl;
    main();

    return 0;
}