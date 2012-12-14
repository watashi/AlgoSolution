#include <stdio.h>
#define INF 999999999
int main()
{
	char ch[5];
	int i,j,n,p,t,d,min,sum,mark[26],map[26][26];

	while(scanf("%d",&n),n){
		for(i=0;i<n;i++){
			mark[i]=map[i][i]=0;
			for(j=i+1;j<n;j++)
				map[i][j]=map[j][i]=INF;
		}
		for(i=1;i<n;i++){
			scanf("%s%d",ch,&p);
			t=ch[0]-'A';
			while(p--){
				scanf("%s%d",ch,&d);
				map[t][ch[0]-'A']=map[ch[0]-'A'][t]=d;
			}
		}
		p=mark[0]=1;
		sum=0;
		while(p<n){
			t=-1;
			min=INF;
			for(i=0;i<n;i++){
				if(mark[i]==0) continue;
				for(j=0;j<n;j++){
					if(mark[j]) continue;
					if(map[i][j]<min){min=map[i][j];t=j;}
				}
			}
			mark[t]=1;
			p++;
			sum+=min;
		}
		printf("%d\n",sum);
	}

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806247 	2539 	Jungle Roads 	Accepted 	ANSI C 	0.008 	2011-05-24 10:39:32 */
/*
id => 1174366
pid => 2539
pname => Jungle Roads
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:02:42
*/
