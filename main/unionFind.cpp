#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
int i,j,n,m,father[10000],a,b;
int find(int x){
	if (x==father[x])
		return x;
	father[x]=find(father[x]);
	return father[x];
}
int main(){
	cin>>n;
	for(i=1;i<=n;i++)
		father[i]=i;
	//读入a,b
	{
		int fa=find(a),fb=find(b);
		if (fa==fb)
			//同一棵树
		else
			father[fa]=fb;//合并
	}//union
	return 0;
}