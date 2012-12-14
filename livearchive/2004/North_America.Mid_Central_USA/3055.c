#include <stdio.h>
int main()
{
	char name[26][26];
	int i,n,ri=0;

	while(scanf("%d",&n),n){
		for(i=0;i<n;i++)
			scanf("%s",name[i]);				
		printf("SET %d\n",++ri);
		for(i=0;i<n;i+=2)
			puts(name[i]);
		if(n%2==0)
			for(i=n-1;i>0;i-=2) puts(name[i]);
		else 
			for(i=n-2;i>0;i-=2) puts(name[i]);
	}

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806272 	3055 	Symmetric Order 	Accepted 	ANSI C 	0.012 	2011-05-24 11:22:31 */
/*
id => 1174370
pid => 3055
pname => Symmetric Order

status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:03:03
*/
