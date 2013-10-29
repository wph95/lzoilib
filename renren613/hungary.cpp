#include<iostream>
#include<cstring>
#include<cmath>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,i,j,k,a,b,ans=0,mat[205]={0};
bool use[205]={0},map[205][205]={0};
bool check(int s){
	for(int i=1;i<=n;i++)
		if (map[s][i]){
		if (!use[i]){
			use[i]=1;
			if (mat[i]==0 or check(mat[i])){
				mat[i]=s;
				return 1;
			}
		}
	}
	return 0;
}
int main(){//匈牙利 二分图最大匹配
	cin>>n>>m;
	for(i=1;i<=m;i++){
		cin>>a>>b;
		map[a][b]=1;
	}
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				map[i][j]=map[i][j]||(map[i][k]&&map[k][j]);
	for(i=1;i<=n;i++){
		memset(use,0,sizeof(use));
		if (check(i))
			ans++;
	}
}