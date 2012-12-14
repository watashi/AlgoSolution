#include <stdio.h>
int main()
{
	int i;
	double x,sum;

	while(scanf("%lf",&x),0.01<=x&&x<=5.20){
		sum=0;
		i=0;
		while(sum<x){
			sum+=1.0/(i+2);
			i++;
		}
		printf("%d card(s)\n",i);
	}

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806226 	2294 	Hangover 	Accepted 	ANSI C 	0.008 	2011-05-24 10:17:24 */
/*
id => 1174330
pid => 2294
pname => Hangover
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 17:58:17
*/
