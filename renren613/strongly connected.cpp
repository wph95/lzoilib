#include<iostream>
#include<cstring>
#include<cmath>
#include<stdio.h>
#include<algorithm>
#define LL long long
using namespace std;
int i,j,k,n,a,b,c,m,t[1005],p=0,kind=0,num[1005][1005],cnt[1005]={0},ans=0,from[1005],yes=0;
int efir[1005]={0},ene[10005],eto[10005],fir[1005]={0},ne[10005],to[10005],e=0,cnt3=0;
bool flag[1005]={0},h[1005]={0};
void dfs1(int x){
	flag[x]=1;
	for(int i=fir[x];i!=0;i=ne[i])
		if (!flag[to[i]])
			dfs1(to[i]);
	t[++p]=x;
}
void dfs2(int x){
	flag[x]=1;
	num[kind][++cnt[kind]]=x;//加入当前kind中
	from[x]=kind;//x属于哪一个分量
	for(int i=efir[x];i!=0;i=ene[i])
		if (!flag[eto[i]])
			dfs2(eto[i]);
}
void dfs3(int x){
	if (!h[from[x]])
		cnt3++;
	flag[x]=1;
	h[from[x]]=1;
	for(int i=efir[x];i!=0;i=ene[i])
		if (!flag[eto[i]])
			dfs3(eto[i]);
}
void add(int a,int b){
	to[++e]=b;
	ne[e]=fir[a];
	fir[a]=e;
	eto[e]=a;
	ene[e]=efir[b];
	efir[b]=e;//反边
}
int main(){ 
	cin>>n>>m;
	for(i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		add(a,b);
	}
	memset(flag,0,sizeof(flag));
	for(i=1;i<=n;i++)
		if (!flag[i])
			dfs1(i);//第一次dfs
	memset(flag,0,sizeof(flag));
	for(i=n;i>1;i--)
		if (!flag[t[i]]){
			kind++;
			dfs2(t[i]);//第二次dfs
		}
}