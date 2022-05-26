#include <bits/stdc++.h>
using namespace std;
void work()
{
    string s;
    cin >> s;
    char c;cin >> c;
    for(int i = 0;i < s.size();i++)
    {
        if(s[i] == c)
        {
            int l = i,r = s.size() - i - 1;
            if(l % 2 == 0 && r % 2 == 0)
            {
                cout << "yes" << endl;
                return;            }
        }
    }
    cout <<"no" << endl;
}
signed main()
{
    int t;cin >> t;
    while(t--) work();
}