#include <stdio.h>
int main()
{
	struct{
		int x;
		char name[10];
	}stu[10];
	int i,n,a,b,c,sum,min,max;

	while(scanf("%d",&n),n+1){
		sum=0;
		for(i=0;i<n;i++){
			scanf("%d%d%d%s",&a,&b,&c,stu[i].name);
			stu[i].x=a*b*c;
			sum+=stu[i].x;
		}
		sum/=n;
		for(i=0;i<n;i++){
			if(stu[i].x>sum) max=i;
			else if(stu[i].x<sum) min=i;
		}
		printf("%s took clay from %s.\n",stu[max].name,stu[min].name);
	}

	return 0;
}

/* # 		Problem 	Verdict 	Language 	Run Time 	Submission Date */
/* 806260 	2782 	Clay Bully 	Accepted 	ANSI C 	0.012 	2011-05-24 11:00:31 */

/*
id => 1174362
pid => 2782
pname => Clay Bully
status => Accepted
lang => ANSI C
time => 0.006
date => 2012-12-14 18:02:22
*/
