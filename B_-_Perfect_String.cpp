#include <bits/stdc++.h>
#define maxn 
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
//#define int long long
using namespace std;
bool cond[200];
signed main()
{
    string s;
    cin >> s;
    bool big = 0,small = 0;
    for(char c:s)
    {
        if(c >= 'A' && c <= 'Z') big = 1;
        if(c >= 'a' && c <= 'z') small = 1;
        int x = int(c);
        if(cond[x]) cout << "No" << endl,exit(0);
        cond[x] = 1;
    }
    if(big && small)cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}