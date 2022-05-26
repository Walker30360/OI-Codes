#include <bits/stdc++.h>
#define maxn 110
#define rd read()
#define pc putchar('\n')
// #define ps putchar(' ')
#define mod 
//#define int long long
#define nosync
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
int n;
int pos[maxn][maxn]; //pos[i][j] 数字i在第j个序列中的位置
int ans = INT_MAX;
void work(int num)
{
    int ps = 0;
    bool fd[maxn]; memset(fd,0,sizeof(fd));
    while(1)
    {
        for(int i = 1;i <= n;i++)
        {
            if(fd[i]) continue;
            bool step = 0;
            if(pos[num][i] == (ps % 10 + 1))
            {
                fd[i] = 1;step = 1;
            }
            if(step) break;
        }
        bool step = 0;
        for(int i = 1;i <= n;i++)
        {
            if(!fd[i]) {step = 1;break;}
        }
        if(!step) break;
        ps++;
    }
    ans = min(ans,ps);
}
signed main()
{
    #ifdef nosync
    ios::sync_with_stdio(false);
    cin.tie(0);
    #endif
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        string s;cin >> s;
        for(int j = 0;j < (int)s.size();j++)
        {
            int x = s[j] - '0';
            pos[x][i] = j+1;
        }
    }
    for(int z = 0;z <= 9;z++)
    {
        work(z);
    }
    cout << ans << endl;

    return 0;
}