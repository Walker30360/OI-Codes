#include <bits/stdc++.h>
using namespace std;
int t;
struct nod{
    int x,y;
}e[5];
bool mp(nod a,nod b){
    return a.y<b.y;
}
void solve()
{
    int x1,x2,x3,y1,y2,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if(y1 == y2 && y1 > y3) cout << abs(x2-x1) << endl;
    else if(y3 == y2 && y3 > y1) cout << abs(x3-x2) << endl;
    else if(y3 == y1 && y1 > y2) cout << abs(x3-x1) << endl;
    else cout << 0 << endl;
}
signed main()
{
    cin >> t;
    while(t--) solve();

    return 0;
}