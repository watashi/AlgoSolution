#include <stdio.h>
#include <string.h>
#define MAXN 255
unsigned int dp[MAXN][MAXN];
int main()
{
	int i,j,k,n,ans;

	memset(dp,0,sizeof(dp));
	for(i=1;i<MAXN;i++){
		for(j=1;j<i;j++)
			dp[i][j]=dp[i][j-1]+dp[i-j][j];
		dp[i][i]=dp[i][i-1]+1;
		for(j=i+1;j<MAXN;j++)
			dp[i][j]=dp[i][i];
	}
	while(scanf("%d",&n)!=EOF && n){
		if(n&1){
			ans=0;
			for(i=1;i<n;i+=2)
				ans+=dp[(n-i)>>1][i];
		}
		else{
			ans=dp[n>>1][n>>1];
			for(i=2;i<n;i+=2)
				ans+=dp[(n-i)>>1][i];
		}
		printf("%d %u\n",n,ans+1);
	}

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 805969 	2560 	Unimodal Palindromic Decompositions 	Accepted 	ANSI C 	0.012 	2011-05-23 16:14:26 */
/*
id => 1174334
pid => 2560
pname => Unimodal Palindromic Decompositions
status => Accepted
lang => ANSI C
time => 0.009
date => 2012-12-14 17:58:48
*/
