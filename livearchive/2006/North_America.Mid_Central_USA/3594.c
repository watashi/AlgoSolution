#include <stdio.h>
int main()
{
	int i,sum;
	char ch;

	while((ch=getchar())!='#'){
		i=sum=0;
		do{
			i++;
			if(ch>='A') sum+=(ch-'A'+1)*i;			
		}while((ch=getchar())!='\n');
		printf("%d\n",sum);
	}

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806314 	3594 	Quicksum 	Accepted 	ANSI C 	0.008 	2011-05-24 11:53:14 */

/*
id => 1174372
pid => 3594
pname => Quicksum
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:03:22
*/
