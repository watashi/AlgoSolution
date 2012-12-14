#include <stdio.h>
int main()
{
	long n,ri=0;
	double d,t,s,v;
	const double PI=3.1415927,inch_mile=12*5280,second_hour=3600;

	while(scanf("%lf%ld%lf",&d,&n,&t),n){
		s=PI*d*n/inch_mile;
		v=s/t*second_hour;
		printf("Trip #%d: %.2lf %.2lf\n",++ri,s,v);
	}

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 805973 	2865 	Biker's Trip Odometer 	Accepted 	ANSI C 	0.008 	2011-05-23 16:20:35 */
/*
id => 1174378
pid => 2865
pname => Biker's Trip Odometer
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:04:24
*/
