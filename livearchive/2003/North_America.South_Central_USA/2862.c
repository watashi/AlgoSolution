#include <stdio.h>
#include <math.h>
int main()
{
	double a,b,c,f0,f1,f2,f3,f4,f5;

	while(scanf("%lf%lf%lf",&f0,&f1,&f2)!=EOF){
		a=(f2-2*f1+f0)/2;
		b=(4*f1-f2-3*f0)/2;
		c=f0;
		f3=9*a+3*b+c;
		f4=16*a+4*b+c;
		f5=25*a+5*b+c;
		printf("%.0lf %.0lf %.0lf\n",f3,f4,f5);
	}

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806297 	2862 	Series Determination 	Accepted 	ANSI C 	0.008 	2011-05-24 11:40:40 */
/*
id => 1174357
pid => 2862
pname => Series Determination
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:01:49
*/
