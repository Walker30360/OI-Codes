#include <bits/stdc++.h>
using namespace std;
bool cmp(char a,char b)
{
    return a<b;
}
signed main()
{
    string s;
    cin >> s;
    int a[200010];int tot = 0;
    for(char c:s)
    {
        a[++tot] = c;
    }
    sort(a+1,a+1+tot);
    for(int i = 1;i <= tot;i++)
    {
        cout << (char)a[i];
    }
    
    return 0;
}