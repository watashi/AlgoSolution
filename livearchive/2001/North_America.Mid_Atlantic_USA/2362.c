#include <stdio.h>
int main()
{
	int i;
	float average,sum=0,a[12];

	for(i=0;i<12;i++){
		scanf("%f",&a[i]);
		sum+=a[i];
	}
	average=sum/12;
	printf("$%.2f\n",average);

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806228 	2362 	Financial Management 	Accepted 	ANSI C 	0.008 	2011-05-24 10:19:51 */
/*
id => 1174354
pid => 2362
pname => Financial Management
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:01:15
*/
