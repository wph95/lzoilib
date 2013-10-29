#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
int i,j,n,m,dis[1005],fir[1005],ne[2005],to[2005],l[2005],e=0,a,b,c,ans=0;
bool h[1005];
queue<int>q;
void add(int u,int v,int d){
	to[++e]=v;
	l[e]=d;
	ne[e]=fir[u];
	fir[u]=e;
}
int main(){
	cin>>n>>m;
	//读边
	memset(dis,-1,sizeof(dis));
	dis[1]=0;
	q.push(1);
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
	return 0;
}