#include <stdio.h>
int main()
{
	int i,h[3];
	const int n=3,H=168;
	
	while(scanf("%d%d%d",&h[0],&h[1],&h[2])!=EOF){
		for(i=0;i<n;i++)
			if(h[i]<=H){
				printf("CRASH %d\n",h[i]);
				break;
			}
		if(i>=n) printf("NO CRASH\n");
	}

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806288 	2857 	Keep on Truckin' 	Accepted 	ANSI C 	0.008 	2011-05-24 11:36:38 */
/*
id => 1174359
pid => 2857
pname => Keep on Truckin'
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:01:56
*/
