#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
struct edge{
	int f,t,l,next;
	}e[10001];
bool operator < (edge x,edge y){
	return x.l>y.l;
}
int i,j,d[200][200]={0},first[200]={0},a,cnt=1,sum=0,n;
bool hash[200]={0};
priority_queue<edge> que;
int main(){
	cin>>n;
	//读边
	for(cnt=first[1];cnt!=-1;cnt=e[cnt].next)
		que.push(e[cnt]);
	hash[1]=1;
	while(!que.empty()){
		edge now=que.top();
		que.pop();
		if (hash[now.t])
			continue;
		hash[now.t]=1;
		sum+=now.l;
		for(cnt=first[now.t];cnt!=-1;cnt=e[cnt].next)
			que.push(e[cnt]);
	}
	cout<<sum;
}