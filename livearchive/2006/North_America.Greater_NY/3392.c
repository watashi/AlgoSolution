#include <stdio.h>
int main()
{
	int I,N,i,n;
	long res;

	scanf("%d",&N);
	I=0;
	while(I<N){
		scanf("%d",&n);
		res=0;
		for(i=1;i<=n;i++)
			res+=i*(i+1)*(i+2)/2;
		printf("%d %d %ld\n",++I,n,res);
	}

	return 0;
}
/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 805977 	3392 	Triangular Sums 	Accepted 	ANSI C 	0.008 	2011-05-23 16:27:33 */

/*
id => 1174351
pid => 3392
pname => Triangular Sums
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:00:52
*/
