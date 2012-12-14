#include <stdio.h>
int main()
{
	float a,b;

	scanf("%f",&a);
	while(scanf("%f",&b),b!=999){
		printf("%.2f\n",b-a);
		a=b;
	}
	printf("End of Output\n");

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806269 	2640 	A Simple Question of Chemistry 	Accepted 	ANSI C 	0.004 	2011-05-24 11:12:57 */
/*
id => 1174346
pid => 2640
pname => A Simple Question of Chemistry
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:00:12
*/
