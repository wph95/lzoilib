#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
int i,j,n,m,dis[10005],dis1[10005],fir[10005],ne[100005],to[100005],l[100005],e=0,a,b,c,ans=0x7fffffff,p;
bool h[10005];
queue<int>q;
void add(int u,int v,int d){
	to[++e]=v;
	l[e]=d;
	ne[e]=fir[u];
	fir[u]=e;
}
void spfa(int c){
	memset(dis,-1,sizeof(dis));
	memset(h,0,sizeof(h));
	if (c==0){
		dis[1]=0;
		q.push(1);
	}
	else{
		dis[n]=0;
		q.push(n);
	}
	while(!q.empty()){
		int now=q.front();
		q.pop();
		h[now]=0;
		for(i=fir[now];i;i=ne[i]){
			int t=to[i],dist;
			dist=l[i]+dis[now];
			if (dist<dis[t] or dis[t]==-1){
				dis[t]=dist;
				if (!h[t]){
					h[t]=1;
					q.push(t);
				}
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	spfa(0);
	memcpy(dis1,dis,sizeof(dis));
	spfa(1);//两次spfa
	for(i=1;i<=n;i++)
		for(j=fir[i];j;j=ne[j]){
			int t=to[j];
			if (dis1[i]+dis[t]+l[j]>dis1[n])
				ans=min(ans,dis1[i]+dis[t]+l[j]);
		}//枚举边
	cout<<ans;
	return 0;
}