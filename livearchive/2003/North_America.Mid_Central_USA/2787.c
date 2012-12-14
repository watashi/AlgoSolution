#include <stdio.h>
int main()
{
	int i,j,n,count,a[20];
	
	while(1){
		count=0;
		if(i=0,scanf("%d",&a[i]),a[i]==-1) break;
		while(a[i]){
			i++;
			scanf("%d",&a[i]);					
		}
		n=i;
		for(i=0;i<n;i++)
			if(a[i]%2==0)
				for(j=0;j<n;j++)
					if(a[i]==2*a[j]){
						count++;
						break;
					}
		printf("%d\n",count);
	}

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806263 	2787 	Doubles 	Accepted 	ANSI C 	0.008 	2011-05-24 11:03:37 */
/*
id => 1174364
pid => 2787
pname => Doubles
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:02:31
*/
