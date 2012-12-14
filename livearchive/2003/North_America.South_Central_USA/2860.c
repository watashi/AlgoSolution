#include <stdio.h>
#include <string.h>
#define eps 1e-8
const int one[5]={0,25,10,5,1};
int cc[5];
int dp[5][505][2];
int main()
{
	int i,j,k,t;
	double A;

	while(scanf("%lf",&A)!=EOF){
		cc[0]=(int)(100*A+0.1);
		memset(dp,0xff,sizeof(dp));
		dp[0][0][0]=0;
		for(i=1;i<=4;i++){
			scanf("%d",&cc[i]);
			for(j=0;j<=cc[i];j++){
				t=j*one[i];
				if(t>cc[0]) break;
				for(k=t;k<=cc[0];k++){
					if(dp[i-1][k-t][0]>=0&&(dp[i][k][0]==-1||dp[i][k][0]>dp[i-1][k-t][0]+j)){
						dp[i][k][0]=dp[i-1][k-t][0]+j;
						dp[i][k][1]=k-t;
					}
				}
			}
		}
		if(dp[4][cc[0]][0]==-1) printf("NO EXACT CHANGE\n");
		else{
			t=cc[0];
			cc[4]=(t-dp[4][t][1])/one[4];
			t=dp[4][t][1];
			cc[3]=(t-dp[3][t][1])/one[3];
			t=dp[3][t][1];
			cc[2]=(t-dp[2][t][1])/one[2];
			t=dp[2][t][1];
			cc[1]=(t-dp[1][t][1])/one[1];
			printf("%d %d %d %d\n",cc[1],cc[2],cc[3],cc[4]);
		}
	}

	return 0;
}
/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806293 	2860 	Exact Change Only 	Accepted 	ANSI C 	0.008 	2011-05-24 11:39:16 */
/*
id => 1174358
pid => 2860
pname => Exact Change Only
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:01:53
*/
