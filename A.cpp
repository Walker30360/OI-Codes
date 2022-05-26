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
    for(int i=1;i<=3;i++) cin>>e[i].x>>e[i].y;
    sort(e+1,e+1+3,mp);
    if(e[1].y==e[2].y){
        cout<<0<<endl;
        return ;
    }
    double ans=0;
    for(int i = 1;i <= 3;i++)
        for(int j = i;j <= 3;j++)
            if(i != j && e[i].y == e[j].y && e[i].y != 0)
            {
                ans += abs(e[j].x - e[i].x);
            }
    printf("%.5lf\n",ans);
}
signed main()
{
    cin >> t;
    while(t--) solve();

    return 0;
}