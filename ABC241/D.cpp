#include <bits/stdc++.h>
#define maxn 200010
using namespace std;
int q;
int mp[maxn];
bool cmp(int x,int y) {return x<y;}
signed main()
{
    cin >> q;
    int tot = 0;
    for(int i = 1;i <= q;i++)
    {
        int t;cin >> t;
        if(t == 1)
        {
            int x;cin >> x;
            mp[++tot] = x;
            sort(mp+1,mp+tot,cmp);
        }
        if(t == 2)
        {
            int x,k;cin >> x >> k;
            deque<int> st;
            for(int i = 1;i <= tot;i++)
            {
                if(mp[i] > x) break;
                st.push_back(mp[i]);
                if(st.size() > k) st.pop_front();
            }
            if(st.size() < k) cout << -1 << endl;
            else cout << st.back() << endl;
        }
        if(t == 3)
        {
            int x,k;cin >> x >> k;
            deque<int> st;
            for(int i = tot;i >= 1;i--)
            {
                if(mp[i] < x) break;
                st.push_back(mp[i]);
                if(st.size() > k) st.pop_front();
            }
            if(st.size() < k) cout << -1 << endl;
            else cout << st.back() << endl;
        }
        // cout << tot << endl;
    }

    return 0;
}