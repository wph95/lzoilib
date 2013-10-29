#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
const int oo=10000;
struct Int{
	int len,num[2000];
	void empty(){
		memset(num,0,sizeof(num));
		len=0;
	}
	void set(){
		num[1]=1;
		len=1;
	}
	void print(){
		printf("%d",num[len]);
		for(int i=len-1;i>=1;i--)
			printf("%04d",num[i]);
		printf("\n");
	}//输出
	void scan(char s[]){
		len=(strlen(s)-1)/4+1; 
		int t=strlen(s)%4;
		if (t==0)
			t=4;
		for(int j=0;j<t;j++)
			num[len]=num[len]*10+s[j]-'0';
		for(int i=len-1;i>=1;i--){
			int j;
			for(j=t;j<t+4;j++)
				num[i]=num[i]*10+s[j]-'0';
			t=j;
		}
	}//将输入的字符串char[]转化为高精度Int
	friend Int operator +(Int x,Int y){
		x.len=max(y.len,x.len);
		for(int i=1;i<=x.len;i++){
			x.num[i]+=y.num[i];
			x.num[i+1]+=x.num[i]/oo;
			x.num[i]%=oo;
		}
		while(x.num[x.len+1]>0)
			x.len++;
		return x;
	}
	friend Int operator -(Int y,Int x){
		Int ret;
		memset(ret.num,0,sizeof(ret.num));
		int flag=1;
		if (x.len>y.len)
			swap(x,y),flag=-1;
		ret.len=y.len;
		for(int i=1;i<=ret.len;i++){
			if (y.num[i]<x.num[i] and i<y.len)
				y.num[i+1]--,y.num[i]+=oo;
			ret.num[i]=y.num[i]-x.num[i];
		}
		while(ret.num[ret.len]==0)
			ret.len--;
		ret.num[ret.len]*=flag;
		return ret;
	}//仅支持正数 大数-小数
	friend Int operator *(Int x,Int y){
		Int ret;
		memset(ret.num,0,sizeof(ret.num));
		ret.len=y.len+x.len-1;
		for(int i=1;i<=x.len;i++)
			for(int j=1;j<=y.len;j++){
				ret.num[i+j-1]+=x.num[i]*y.num[j];
				ret.num[i+j]+=ret.num[i+j-1]/oo;
				ret.num[i+j-1]%=oo;
			}
		while(ret.num[ret.len+1]>0){
			ret.len++;
			ret.num[ret.len+1]=ret.num[ret.len]/oo;
			ret.num[ret.len]%=oo;
		}
		return ret;
	}
}a,b,c;
char x[1005],y[1005];
int n,m,i,j,k;
int main(){
	cin>>x>>y;
	a.scan(x);
	b.scan(y);
	c.set();
	c.print();
	c=a+b;
	c.print();	
	c=a-b;
	c.print();
	c=a*b;
	c.print();
	return 0;
}