#include <stdio.h>
int main()
{
	int i;
	double x=1,e=0;

	printf("n e\n- -----------\n");
	for(i=0;i<=9;i++){
		if(i) x=x*i;
		e+=1.0/x;
		if(i==0||i==1) printf("%d %.0lf\n",i,e);
		else if(i==2) printf("%d %.1lf\n",i,e);
		else printf("%d %.9lf\n",i,e);
	}

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 805909 	2083 	u Calculate e 	Accepted 	ANSI C 	0.004 	2011-05-23 15:02:39 */
/*
id => 1174343
pid => 2083
pname => u Calculate e
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 17:59:47
*/
