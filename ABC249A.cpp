#include <bits/stdc++.h>
#define maxn 
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
//#define int long long
using namespace std;
int a,b,c,d,e,f,x;

signed main()
{
    cin >> a >> b >> c >> d >> e >> f >> x;
    int len1 = 0,len2 = 0;
    int tot1 = a;
    for(int i = 1;i <= x;i++)
    {
        len1 += b;
        tot1--;
        if(tot1 == 0) i += c,tot1 = a;
    }
    tot1 = d;
    for(int i = 1;i <= x;i++)
    {
        len2 += e;
        tot1--;
        if(tot1 == 0) i += f,tot1 = d;
    }
    if(len1 > len2) cout << "Takahashi" << endl;
    else if(len1 < len2) cout << "Aoki" << endl;
    else cout << "Draw" << endl; 

    return 0;
}