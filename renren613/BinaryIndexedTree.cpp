#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cctype>
using namespace std;
int n,m,i,j,k,q,x,y,c[1025]={0};
int lowbit(int x){
	return x&(-x);
}
int sum(int x){
    int sum = 0; 
	for(int i=x;i>0;i-=lowbit(i))
			sum += c[i]; 
    return sum; 
}//求和
void pl(int x,int num){
	for(int i=x;i<=n;i+=lowbit(i))
          c[i] += num; 
}//修改：a[x]+num,则对应的c[]都要+num
int main(){
	//树状数组 原数组为a[],树状数组为c[]
	return 0;
}