#include<bits/stdc++.h>
using namespace std;
int n,TYPE1,TYPE2,TYPE3;
const int m=30,full=(1<<30)-1;
int _[30];

struct segment_tree{
	#define maxn 1000006
	#define mid ((l+r)>>1)
	#define ls x<<1
	#define rs x<<1|1
	int s[maxn<<2],lzy[maxn<<2],l0[maxn<<2],l1[maxn<<2];
	inline void modify(int x,int l,int r,int A)
	{
		if(A==full)s[x]=A,l0[x]=0,l1[x]=r-l+1,lzy[x]=1;
		else       s[x]=A,l1[x]=0,l0[x]=r-l+1,lzy[x]=-1;
	}
	inline void pushdown(int x,int l,int r)
	{
		if(!lzy[x])return ;
		modify(ls,l,mid,lzy[x]>0?full:0),
		modify(rs,mid+1,r,lzy[x]>0?full:0);
		lzy[x]=0;
	}
	inline void pushup(int x,int l,int r)
	{
		l0[x]=(l0[ls]==mid-l+1)*l0[rs]+l0[ls],
		l1[x]=(l1[ls]==mid-l+1)*l1[rs]+l1[ls];
	}
	int ins(int x,int l,int r,int P,int A)
	{
		int f=0;
		if(l==r)
		{
			s[x]+=A,l0[x]=l1[x]=0;
			if(s[x]>full)s[x]&=full,f=1;
			if(s[x]<0)s[x]+=full+1,f=1;
			if(s[x]==full)l1[x]=1;
			if(!s[x])l0[x]=1;
			return f;
		}pushdown(x,l,r);
		if(P<=mid) f=ins(ls,l,mid,P,A);
		if(P>mid) f=ins(rs,mid+1,r,P,A);
		pushup(x,l,r);return f;
	}
	void cover(int x,int l,int r,int L,int R,int A)
	{
		if(L<=l&&r<=R)return modify(x,l,r,A);
		pushdown(x,l,r);
		if(L<=mid)cover(ls,l,mid,L,R,A);
		if(R>mid) cover(rs,mid+1,r,L,R,A);
		pushup(x,l,r);
	}
	int ask(int x,int l,int r,int P,int k)
	{
		if(l==r)return s[x]>>k&1;
		pushdown(x,l,r);
		if(P<=mid) return ask(ls,l,mid,P,k);
		return ask(rs,mid+1,r,P,k);
	}
	int ask1(int x,int l,int r,int P,int len)//P:starting position
	{
		if(l==r)return l1[x]?len+1:0;
		pushdown(x,l,r);
		if(P<=mid)return ask1(ls,l,mid,P,len*(l1[rs]==r-mid)+l1[rs]);
		return ask1(rs,mid+1,r,P,len);
	}
	int ask0(int x,int l,int r,int P,int len)//P:starting position
	{
		if(l==r)return l0[x]?len+1:0;
		pushdown(x,l,r);
		if(P<=mid)return ask0(ls,l,mid,P,len*(l0[rs]==r-mid)+l0[rs]);
		return ask0(rs,mid+1,r,P,len);
	}
	void out(int x,int l,int r)
	{
		if(s[x]|lzy[x]|l0[x]|l1[x])
			cout<<x<<' '<<l<<' '<<r<<' '<<s[x]<<' '<<lzy[x]<<' '<<l0[x]<<' '<<l1[x]<<'\n';
		if(l==r)return ;out(ls,l,mid),out(rs,mid+1,r);
	}
	#undef maxn
	#undef ls
	#undef rs
	#undef mid
}ST;

inline int read()
{
	int r=0,f=0;char c=getchar();
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))r=r*10+(c^'0'),c=getchar();
	return f?-r:r;
}
int main()
{
	n=read(),TYPE1=read(),TYPE2=read(),TYPE3=read();
	ST.modify(1,0,1e6,0);for(int i=0;i<30;i++)_[i]=(1<<i+1)-1;
	
	int op,x,y;
	for(int i=1;i<=n;i++)
	{
//		ST.out(1,0,1e6);
		op=read(),x=read();
		if(op==1)
		{
			y=read();if(!x)continue;
			int bl=y/m,k=y%m;
			if(x>0)
			{
				int tmp=ST.ins(1,0,1e6,bl,(x&_[m-k-1])<<k);
				x>>=m-k,x+=tmp;if(!x)continue;
				tmp=ST.ins(1,0,1e6,bl+1,x);if(!tmp)continue;
				int r=ST.ask1(1,0,1e6,bl+2,0);ST.cover(1,0,1e6,bl+2,bl+2+r-1,0);
				ST.ins(1,0,1e6,bl+2+r,1);
			}else{
				x=-x;
				int tmp=ST.ins(1,0,1e6,bl,-(x&_[m-k-1])<<k);
				x>>=m-k,x+=tmp;if(!x)continue;
				tmp=ST.ins(1,0,1e6,bl+1,-x);if(!tmp)continue;
				int r=ST.ask0(1,0,1e6,bl+2,0);ST.cover(1,0,1e6,bl+2,bl+2+r-1,full);
				ST.ins(1,0,1e6,bl+2+r,-1);
			}
		}else{
			int bl=x/m,k=x%m;
			cout<<ST.ask(1,0,1e6,bl,k)<<'\n';
		}
	}return 0;
}
