#include <bits/stdc++.h>
#define maxn 
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
//#define int long long
using namespace std;
string s[50];
bool cond[50][30];
int n,k,ans;
void dfs(int lst,int ths,int dep,int now)
{
    if(dep == k+1) {ans = max(ans,now); return;}
    int less = 0;
    for(char i = 'a';i <= 'z';i += 1)
    {
        if(cond[lst][i]==cond[ths][i] && cond[lst][i] == 1) continue;
        else now--,less++;
    }
    for(int i = ths+1;i <= n;i++)
        dfs(ths,i,dep+1,now);
    now += less;
    return;
}
signed main()
{
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        cin >> s[i];
        for(char c:s[i])
        {
            int x = c - 'a' + 1;
            cond[i][x] = 1;
        }
    }
    for(int i = 2;i <= n;i++)
        dfs(1,i,2,26);
    cout << ans << endl;

    return 0;
}