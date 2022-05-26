#include <bits/stdc++.h>
#define maxn 
using namespace std;
int n;
int mp[1010][1010];
//line
void dfsl(int x,int y,int len,int change)
{
    if(y > n) return;
    if(x > n) return;
    if(len == 6) {cout << "Yes" << endl;exit(0);}
    cout << len << " ";
    if(mp[x][y] == 1)
    {
        dfsl(x+1,y,len+1,change);
    }
    else
    {
        if(change)
            dfsl(x+1,y,len+1,change-1);
        else
            return;
    }
    dfsl(x+1,y,len,change);
}
signed main()
{
    cin >> n;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
        {
            char c;cin >> c;
            if(c == '#') mp[i][j] = 1;
        }
    for(int i = 1;i <= n;i++)
        dfsl(1,i,0,2),cout << endl << "*";

    return 0;
}