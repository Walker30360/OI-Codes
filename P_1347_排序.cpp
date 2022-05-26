#include <bits/stdc++.h>
#define maxn 
#define mod
#define rd read()
//#define int long long
//#define nosync
typedef long long ll;
typedef long double ld;
using namespace std;
//Quick Read and Write
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
    void write(double x){printf("%0.2lf",x);}
    void write(string s){for(char c:s)putchar(c);}
    template<typename type1,typename type2,typename ...typen>
    void write(type1 a1,type2 a2,typen ...an){
        write(a1);
        write(a2,an...);
    }
}using namespace IO;
//init structs

//init numbers
int n,m;
//init functions

//main
signed main()
{
    //nosync
	#ifdef nosync
    ios::sync_with_stdio(false);
    cin.tie(0);
    #endif
    //code
	n = rd,m = rd;
    for(int i = 1;i <= m;i++)
    {
        char cha1 = getchar(),md = getchar(),cha2 = getchar();
        
    }

	return 0;
}