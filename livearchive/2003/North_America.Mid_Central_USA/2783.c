#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) ((a>b)?a:b)
int comp(const int *a,const int *b)
{
	return (*a<*b)?-1:1;
}
int main()
{
	int i,j,k,tmp,temp,ans,c[24],p[24][24];

	while(scanf("%d%d",&i,&j),i!=-1){
		for(k=0;k<24;k++)
			c[k]=0;
		while(i){
			i--;j--;
			p[i][c[i]++]=j;
			scanf("%d%d",&i,&j);
		}
		for(k=0;k<24;k++)			
			qsort(p[k],c[k],sizeof(int),comp);
		ans=0;
		for(k=0;k<24;k++){
			if(c[k]==0) continue;
			ans++;
			temp=p[k][c[k]-1];
			for(i=k+1;i<24;i++){
				if(c[i]==0) continue;/*!!!!!*/
				tmp=temp;
				temp=MAX(p[i][c[i]-1],temp);
				while(c[i]&&p[i][c[i]-1]>=tmp) c[i]--;
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806262 	2783 	Robots 	Accepted 	ANSI C 	0.004 	2011-05-24 11:01:38 */
/*
id => 1174363
pid => 2783
pname => Robots
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:02:27
*/
