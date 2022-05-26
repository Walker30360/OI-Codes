#include <bits/stdc++.h>
using namespace std;
int a,b,x;
double c;

signed main()
{
    cin >> a >> b >> c >> x;
    if(x <= a) cout << 1 << endl,exit(0);
    if(x > b) cout << 0 << endl,exit(0);
    double p = b-a;
    printf("%.10lf",c/p);
    
    return 0;
}