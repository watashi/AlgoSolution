#include <stdio.h>
#define PI 3.14159265358979
int main()
{
	double x,y,z;
	int n,i;

	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lf%lf",&x,&y);
		z=(x*x+y*y)*PI/100.0+1.0;
		printf("Property %d: This property will begin eroding in year %d.\n",i+1,(int)z);
	}
	printf("END OF OUTPUT.\n");

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806235 	2363 	I Think I Need a Houseboat 	Accepted 	ANSI C 	0.012 	2011-05-24 10:25:14 */
/*
id => 1174353
pid => 2363
pname => I Think I Need a Houseboat
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:01:02
*/
