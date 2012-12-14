#include <stdio.h>
int main()
{
	int i,j,n,a[30],sum1,sum2;

	while(scanf("%d",&n),n!=0){
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++){
			sum1=sum2=0;
			for(j=0;j<=i-1;j++)
				sum1+=a[j];
			for(j=0;j<=n-1-i;j++)
				sum2+=a[n-1-j];
			if(sum1==sum2) break;
		}
		if(sum1==sum2) printf("Sam stops at position %d and Ella stops at position %d.\n",i-1+1,i+1);
		else printf("No equal partitioning.\n");
	}
	
	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806244 	2535 	Magnificent Meatballs 	Accepted 	ANSI C 	0.008 	2011-05-24 10:36:57 */
/*
id => 1174368
pid => 2535
pname => Magnificent Meatballs
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:02:54
*/
