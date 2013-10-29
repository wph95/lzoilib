#include<iostream>
#include<cstring>
#include<cmath>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct bridge{
	int x,y;
}br[10005];
int i,j,n,m,a,b,fir[155]={0},ne[10005],to[10005],e=0,vis[155], dfn[155], low[155],nbri=0;
bool cmp(bridge a,bridge b){
	if (a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}
void add(int u, int v){
	to[++e]=v;
	ne[e]=fir[u];
    fir[u]=e;
}
void dfs(int u, int fa,int cnt){
    int v, i;
    vis[u] = 1;
    dfn[u] = low[u] = cnt;
    for(i=fir[u];i!=0;i=ne[i]){
        v = to[i];
        if(vis[v] == 1 && v!= fa )
            low[u] = min(low[u], dfn[v]);
		if(vis[v] == 0){
            dfs(v,u,cnt+1);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]){
               br[++nbri].x=min(u,v);
               br[nbri].y=max(u,v);
			}
        }
    }
    vis[u] = 2;
}
int main(){
	cin>>n>>m;
	for(i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dfs(1,1,1);
	sort(br+1,br+1+nbri,cmp);
	for(i=1;i<=nbri;i++)
		printf("%d %d\n",br[i].x,br[i].y);//输出桥
    return 0;
}