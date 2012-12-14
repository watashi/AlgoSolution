#include <stdio.h>
const char id[6][24]={"valid athlete","valid reserve","valid judge","valid staff","valid press","invalid"};
const int g[10]={1,5,7,6,2,8,3,0,9,4};
int f(int i,int j)
{
	if(i==0) return j;
	else if(i==1) return g[j];
	else return f(i-1,g[j]);
}
/*
int doit(int i,int j)
{
	if(i<5&&j<5) return (i+j)%5;
	else if(i<5&&j>=5) return (i+(j-5))%5+5;
	else if(i>=5&&j<5) return ((i-5)-j)%5+5;
	else return (i-j)%5;
}
*/
int doit(int i,int j)
{
	int res;
	
	if(i<5&&j<5) {res=(i+j)%5;while(res<0) res+=5;}
	else if(i<5&&j>=5) {res=(i+(j-5))%5+5;while(res<5) res+=5;}
	else if(i>=5&&j<5) {res=((i-5)-j)%5+5;while(res<5) res+=5;}
	else {res=(i-j)%5;while(res<0) res+=5;}
	return res;
}
int main()
{
	char str[24];
	int i,t,n,m,re,b,a[8];
	
	scanf("%d",&re);
	while(re--){
		scanf("%s",str);
		n=0;
		for(i=0;str[i];i++){
			n*=5;
			switch(str[i]){
			case 'V':n+=4;break;
			case 'W':n+=3;break;
			case 'X':n+=2;break;
			case 'Y':n+=1;break;
			case 'Z':break;
			}
		}
		if(n>=100000000){
			printf("%s/%d is invalid id number\n",str,n);
			continue;
		}
		t=n;
		for(i=0;i<8;i++){
			a[i]=t%10;
			t/=10;
			if(i==7) b=a[i]/2;
			a[i]=f(i,a[i]);
			if(i) m=doit(m,a[i]);
			else m=a[i];
		}
		if(m) b=5;
		printf("%s/%08d is %s id number\n",str,n,id[b]);
	}

	return 0;
}
/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806259 	2017 	Hey, You're Not Marion Jones! 	Accepted 	ANSI C 	0.032 	2011-05-24 10:58:19 */
/*
id => 1174340
pid => 2017
pname => Hey, You're Not Marion Jones!
status => Accepted
lang => ANSI C
time => 0.022
date => 2012-12-14 17:59:25
*/
