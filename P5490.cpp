//离散化

#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
#define maxn 1000100
#define rd read()
#define mid ((t[now].l + t[now].r) >> 1)
#define ls (now << 1) 
#define rs ((now << 1) | 1) 
using namespace std;
inline int read(){long long s=0,w=1;char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();} while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar(); return s*w;}
inline void write(int x) {if(x < 0) putchar('-'),x=-x;static int sta[35];int top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top) putchar(sta[--top] + 48);}
int n;
//离散化数组与标记
int tmp[maxn << 2],tot;

//离散化之后离散化值对应的y值
int ypos[maxn << 2];

//防止扫描到左右端点
int mx = 1 << 31;

//每一条竖线
struct line
{
    int x; //线段x坐标
    int end; //矩形最终结束的y2
    int left; //对应的左边线段
    int flag; //判断是矩形左or右界，左1右-1
}l[maxn << 2];
//线段树
struct tree
{
    int l,r; //区间左右端点
    int len; //该节点代表的区间被矩形覆盖的长度
    int cnt; //代表区间被覆盖的次数
}t[maxn << 2];
//线段排序
bool cmp(line x,line y)
{
    if(x.x != y.x) return x.x < y.x; //两者不在同一x上，选择左边的
    else return x.flag > y.flag; //细节：在同一直线上，选择左边的
}
//上传
void pushup(int now)
{
    if(t[now].l == mx && t[now].r == mx) return; //细节：端点跳过
    if(!t[now].cnt) {t[now].len = t[ls].len + t[rs].len;return;} //没有被覆盖，那么长度就取决于左右儿子
    t[now].len = ypos[t[now].r + 1] - ypos[t[now].l];
}
//建树
void build(int l,int r,int now)
{
    t[now].l = l; t[now].r = r;
    if(l == r) return; 
    build(l,mid,ls); build(mid+1,r,rs);
}
//添加值
void modify(int now,int l,int r,int v)
{
    if(l <= t[now].l && t[now].r <= r) {t[now].cnt += v;/*区间这个点+1/-1*/ pushup(now);return;}
    if (l <= mid) modify(ls, l, r, v);
	if (mid < r) modify(rs, l, r, v);
	pushup(now);
}

signed main()
{
    int ans = 0;
    n = read();
    for(int i = 1;i <= n;i++)
    {
        int x1 = rd,y1 = rd,x2 = rd,y2 = rd;
        //记录线段信息
        #define lt ((i << 1) - 1)
        #define rt ((i << 1))
        l[lt].x = x1; l[rt].x = x2; //存储对应矩形的x坐标，左边即为lt，右边即为rt
        l[lt].left = l[rt].left = y1; //记录左侧线段
        l[lt].end = l[rt].end = y2; // 记录高度
        l[lt].flag = 1; /*左侧*/ l[rt].flag = -1; /*右侧*/
        #undef lt
        #undef rt
        tmp[++tot] = y1; tmp[++tot] = y2;
    }
    sort(tmp+1,tmp+1+(n << 1));
    tot = unique(tmp+1,tmp+1+(n << 1)) - tmp - 1;
    for(int i = 1;i <= (n << 1);i++)
    {
        int end = lower_bound(tmp+1,tmp+1+tot,l[i].end) - tmp; //查找高度
        int lft = lower_bound(tmp+1,tmp+1+tot,l[i].left) - tmp; //查找左端
        ypos[end] = l[i].end; ypos[lft] = l[i].left;
        l[i].end = end; l[i].left = lft;
        mx = max(mx,end);
    }
    sort(l+1,l+1+(n << 1),cmp);
    build(1,n << 1,1);
    for(int i = 1;i < (n << 1);i++)
    {
        modify(1,l[i].left,l[i].end - 1,l[i].flag); //给区间中每个节点加flag
        ans += t[1].len * (l[i + 1].x - l[i].x);//根节点的len * 与下一条线段的距离 = 这一块内的矩形面积
    }
    write(ans);

    return 0;
}