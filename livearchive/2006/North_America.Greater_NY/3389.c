#include <stdio.h>
int main()
{
	int i,n,c,q25,d10,n5,p1;

	while(scanf("%d",&n)!=EOF){
		for(i=1;i<=n;i++){
			scanf("%d",&c);
			q25=d10=n5=p1=0;
			q25=c/25;
			c%=25;
			d10=c/10;
			c%=10;
			n5=c/5;
			p1=c%5;
			printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",i,q25,d10,n5,p1);
		}
	}
	
	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 805976 	3389 	Quick Change 	Accepted 	ANSI C 	0.012 	2011-05-23 16:26:19 */
/*
id => 1174352
pid => 3389
pname => Quick Change
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:00:57
*/
