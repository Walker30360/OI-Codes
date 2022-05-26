#include <bits/stdc++.h>
#define maxn 110
#define m n+1
#define rd read()
#define pc putchar('\n')
#define ps putchar(' ')
//#define int long long
using namespace std;
namespace IO{
     inline int read(){
        int x=0;int f=1;char ch;
        while((ch=getchar())<'0'||x>'9')if(ch=='-')f=-1;
        while(ch>='0'&&ch<='9'){x=((x<<1)+(x<<3)+(ch^48)),ch=getchar();}
        return x*f;
    }
    void write(char x){putchar(x);}
    void write(const char *x){for(;*x;++x)putchar(*x);}
    void write(char *x){for(;*x;++x)putchar(*x);}
    void write(signed x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar('0'+x-x/10*10);}
    void write(long long x){
        if(x<0)putchar('-'),x=-x;
        if(x>9)write(x/10);
        putchar('0'+x-x/10*10);
    }
    void write(double x){printf("%.2lf",x);}
    void write(string s){for(char c:s)putchar(c);}
    template<typename type1,typename type2,typename ...typen>
    void write(type1 a1,type2 a2,typen ...an){
        write(a1);
        write(a2,an...);
    }
}using namespace IO;
double a[maxn][maxn];
int n;
void Gauss()
{
    for(int i = 1;i <= n;i++)
    {
        bool flag = 0;
        for(int j = i;j <= n;j++)
            if(a[i][j] != 0)
            {
                flag = 1;
                for(int k = 1;k <= m;k++) swap(a[i][k],a[j][k]);
                break;
            }
        if(!flag) {write("No Solution",'\n');exit(0);}
        double tt = a[i][i];
        for(int j = 1;j <= m;j++) a[i][j] /= tt;
        for(int j = 1;j <= n;j++)
            if(j != i)
            {
                double tt = a[j][i];
                for(int k = 1;k <= n+1;k++) a[j][k] -= tt * a[i][k];
            }
    }
    for(int i = 1;i <= n;i++) write(a[i][m],'\n');
}
signed main()
{
    n = rd;
    for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) a[i][j] = rd;
    Gauss();

    return 0;
}