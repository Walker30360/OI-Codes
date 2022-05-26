#include <bits/stdc++.h>
#define maxn 10000010
using namespace std;
int t;
basic_string<int> ans;
bool vis[maxn];
void work()
{
    int p,q;
    cin >> p >> q;
    ans.clear();
    memset(vis,0,sizeof(vis));
    int more = 1;
    //模拟高精
    while(more != q) //找到之前
    {
        ans += ((more * 10) / p);
        more = more * 10 % p;
        if(vis[more]) //Loop
        {
            cout << -1 << endl;
            return; //NO
        }
        vis[more] = 1;
    }
    //判断答案是否满足十位
    int wei = 0,anssiz = ans.size();
    while(wei + 1 < anssiz && ans[wei] == 0) //前导零个数
        wei++;
    for(int i = max(wei,anssiz - 10);i < anssiz;i++)
    {
        cout << ans[i];
    }
    cout << "\n";
    return;
}
signed main()
{
    cin >> t;
    while(t--)
    {
        work();
    }
}