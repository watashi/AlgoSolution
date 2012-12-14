#include <stdio.h>
#include <stdlib.h>
int main()
{
	int t,a,b,d,dd,bl=0;

	while(scanf("%d",&t),t!=5280){
		if(bl) printf("\n");
		else bl=1;
		a=0;
		d=abs(t);
		while(scanf("%d",&b)){
			printf("Moving from %d to %d: ",a,b);
			if(b==t){
				printf("found it!\n");
				break;
			}
			dd=abs(b-t);
			if(d==dd) printf("same.\n");
			else if(d<dd) printf("colder.\n");
			else if(d>dd) printf("warmer.\n");
			d=dd;
			a=b;
		}
	}

	return 0;
}
/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806256 	2014 	Are We There Yet? 	Accepted 	ANSI C 	0.036 	2011-05-24 10:57:26 */
/*
id => 1174339
pid => 2014
pname => Are We There Yet?
status => Accepted
lang => ANSI C
time => 0.029
date => 2012-12-14 17:59:15
*/
