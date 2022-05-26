#include <bits/stdc++.h>
#define rd read()
using namespace std;
priority_queue<int> win,lose;
inline int read(){long long s=0,w=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();} while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;}
inline void write(int x) {if(x < 0) putchar('-'),x=-x;static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);}
signed main()
{
    int ans = 0;
    int n;
    n = read();
    for(int i = 1;i <= n;i++)
    {
        int x;x = rd;
        if(i == 1) {lose.push(-1 * x);continue;}
        win.push(-1 * x);
        if(win.size() > lose.size())
        {
            lose.push(win.top());
            win.pop();
        }
    }
    while(!win.empty())
    {
        ans += -1 * win.top();win.pop();
    }
    while(!lose.empty())
    {
        ans -= -1 * lose.top();lose.pop();
    }
    write(ans);
}