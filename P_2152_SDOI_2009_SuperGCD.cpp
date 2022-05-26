#include <bits/stdc++.h>
#define maxn 
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
//#define int long long
using namespace std;
inline int read(){long long s=0,w=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();} while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;}
inline void write(int x) {if(x < 0) putchar('-'),x=-x;static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);}
string operator/(const string& a,const int& b)
{
    string c;int d = 0;
    string ax;
    for (int i = 1;i < a.length();i++) ax += a[i] - 48;   //字符串转数字
    for (int i = 0;i < a.length();i++)
        c.push_back((d*10+ax[i])/b+48),d=(d*10+ax[i])%b;  //模拟竖式
    for (int i=0;c[0]==48;i++)c.erase(c.begin(),c.begin()+1);   //去0
    return c;
}
string operator-(const string& a,const string& b)
{
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a,b;cin >> a >> b;
    while(1)
    {
        int wa = a[a.size()-1] - 48,wb = b[b.size()-1]-48;
        if(wa % 2 == 0 && wb % 2 == 0)
        {
            a = a/2,b = b/2;
            continue;
        }

    }

    return 0;
}