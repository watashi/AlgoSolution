#include <stdio.h>
int main()
{
	int ri,repeat,n,i,j,a[123];

	scanf("%d",&repeat);
	for(ri=1;ri<=repeat;ri++){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			a[i]=0;
		for(j=1;j<=n;j++)
			for(i=1;i<=n/j;i++)
				a[j*i]=!a[j*i];
		j=0;
		for(i=1;i<=n;i++)
			if(a[i]) j++;
		printf("%d\n",j);
	}

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 805964 	2557 	The Drunk Jailer 	Accepted 	ANSI C 	0.024 	2011-05-23 16:10:42 */
/*
id => 1174332
pid => 2557
pname => The Drunk Jailer
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 17:58:32
*/
